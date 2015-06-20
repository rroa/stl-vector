#pragma once

#include <cassert>
#include <exception>

namespace raulroa
{
	template <typename T>
	class Vector
	{
	public:
		typedef size_t size_type;		
		typedef T value_type;
		typedef T* iterator;
		typedef const T* const_iterator;

		// CTOR
		//
		explicit Vector( size_t initialSize = 0, const T& initialValue = T() )
			: size_( initialSize )			
		{
			m_start_ = allocate( initialSize, initialValue );			
			m_finish_ = m_start_ + initialSize;
			m_end_of_storage_ = m_start_ + initialSize ;
		}		
		
		Vector( const Vector& other )
		{
			const size_type usedSize = size_t( other.size() );

			m_start_ = allocate( usedSize );			
			m_finish_ = m_start_ + usedSize;
			m_end_of_storage_ = m_start_ + usedSize ;

			copy( m_start_, other.m_start_, usedSize );
		}

		~Vector()
		{
			destroy( m_start_, m_finish_ );
			deallocate( m_start_ );
		}

		/* REQUIRED INTERFACE */		

		// BEGIN & END
		//
		iterator begin() 
		{ 
			return iterator( m_start_ ); 
		}
		
		const_iterator begin() const 
		{ 
			return const_iterator( m_start_ ); 
		}
		
		iterator end() 
		{ 
			return iterator( m_finish_ ); 
		}

		const_iterator end() const 
		{ 
			return const_iterator( m_finish_ ); 
		}

		// SIZE, CAPICITY & MAX SIZE
		size_type size() const  
		{  
			return size_type( end() - begin() );
		} 

		size_type capacity() const 
		{ 
			return size_type( m_end_of_storage_ - begin() ); 
		}

		size_type max_size() const 
		{ 
			return size_type( -1 ) / sizeof( T ); 
		}

		bool empty() const 
		{ 
			return begin() == end(); 
		}

		void reserve( size_t newCapacity )
		{
			if ( capacity() < newCapacity ) 
			{
				const size_type oldSize = size();
				iterator tmp = allocate( newCapacity );

				// fwd copy
				//
				copy( tmp, m_start_, oldSize );
				
				// symphony of destruction!
				//
				destroy( m_start_, m_finish_ );
				deallocate( m_start_ );
				
				m_start_ = tmp;
				m_finish_ = tmp + oldSize;
				m_end_of_storage_ = m_start_ + newCapacity;
			}
		}

		void clear() 
		{ 
			erase( begin(), end() ); 
		}

		void resize( size_t newCapacity ) 
		{ 
			resize( newCapacity, T() ); 
		}
		
		void resize( size_t newSize, const T& initialValue )
		{
			if( newSize < size() )
			{
				erase( begin() + newSize, end() );
			}
			else
			{
				size_t expansion = newSize - size();
				for( size_t i = 0; i <  expansion; ++i )
				{
					insert( end(), initialValue );
				}
			}
		}

		T& at( size_t n )
		{
			if( n >= size() ) throw std::out_of_range( "The provided index is out of range." );			
			return ( *this )[ n ];
		}

		const T& at( size_t n ) const
		{
			if( n >= size() ) throw std::out_of_range ( "The provided index is out of range." );
			return ( *this )[ n ];
		}

		T& front() 
		{ 
			return *begin(); 
		}

		const T& front() const 
		{ 
			return *begin(); 
		}
		
		T& back() 
		{ 
			return *( end() - 1 ); 
		}
		
		const T& back() const 
		{ 
			return *( end() - 1 ); 
		}

		void push_back( const T& element )
		{
			if ( m_end_of_storage_ > m_finish_ && m_finish_ != m_end_of_storage_ ) 
			{
				new( m_finish_ ) T( element );
				++m_finish_;
			}
			else
			{
				insert( end(), element );
			}
		}

		void pop_back()
		{
			--m_finish_;
			m_finish_->~T();
		}

		iterator insert( iterator position, const T& element )
		{
			size_type n = position - begin();
			assert( ( n <= size() ) );
			if ( m_finish_ != m_end_of_storage_ && position == end() ) 
			{
				new( m_finish_ ) T( element );
				++m_finish_;
			}
			else
			{
				if ( m_finish_ !=  m_end_of_storage_ ) 
				{
					new( m_finish_ ) T( *( m_finish_ - 1 ) );
					
					++m_finish_;
					T elementCopy = element;
					copy_backward( m_finish_ - 1, position, sizeof( m_start_ ) - 2 );
					*position = elementCopy;
				}
				else
				{
					const size_type oldSize = size();
					const size_type newSize = oldSize != 0 ? size_t( 1.5 * oldSize ) : 1;
					iterator newStart = allocate( newSize );
					iterator newFinish = newStart;
					
					copy( newFinish, m_start_, size_t( position - begin() ) );										
					
					newFinish += n;
					new( newFinish ) T( element );
					++newFinish;
					
					size_t nBytes = size_t( end() - position );
					copy_backward( newFinish, m_start_ + n,  nBytes);

					destroy( m_start_, m_finish_ );

					deallocate( m_start_ );
					
					size_ =  newSize;
					m_start_ = newStart;
					m_finish_ = newFinish + nBytes;
					m_end_of_storage_ = newStart + newSize;
				}
			}
			return begin() + n;
		}

		iterator erase( iterator position ) 
		{ 
			return erase( position, position + 1 );
		}

		iterator erase( iterator first, iterator last )
		{						
			iterator i = copy( first, last, size_t( m_finish_ - last ) );
			//destroy( i, m_finish_ );
			destroy( first, last );
			m_finish_ = m_finish_ - ( last - first );
			
			return i;
		}

		// OPERATORS
		//
		T& operator[]( size_type n )
		{ 
			assert( n < size_ );
			return *( begin() + n );
		}

		const T& operator[]( size_type n ) const
		{
			assert( n < size_ );
			return *( begin() + n );
		}

		bool operator==( const Vector< T >& other ) const			
		{		
			// if the sizes are not the same: not equal
			//
			if( this->size() != other.size() ) return false;

			// if all the pointers are the same: equal
			//
			if( m_start_ == other.m_start_ && 
				m_finish_ == other.m_finish_ && 
				m_end_of_storage_ == other.m_end_of_storage_ ) 
				return true;

			// if one of the values are not the same: not equal
			//
			for( size_t i = 0; i < size(); ++i )
				if( *( m_start_ + i ) != *( other.m_start_ + i ) ) return false;

			return true;
		}


		Vector& operator=( const Vector& other )
		{
			if( this == &other )
			{
				return *this;
			}

			if( m_start_ )
			{
				destroy( m_start_, m_finish_ );
				deallocate( m_start_ );
			}

			const size_type usedSize = size_t( other.size() );

			m_start_ = allocate( usedSize );			
			m_finish_ = m_start_ + usedSize;
			m_end_of_storage_ = m_start_ + usedSize ;

			copy( m_start_, other.m_start_, usedSize );

			return *this;
		}

	private:
		T* m_start_;
		T* m_finish_;
		T* m_end_of_storage_;
		size_type size_;

		static T* allocate( size_t elements )
		{
			T* begin_ = reinterpret_cast< T* >( ::operator new( elements * sizeof( value_type )));
			T* end_ = begin_ + elements;

			for( T* p = begin_; p != end_; ++p )
			{
				new( p ) T;						// Placement new.
			}

			return begin_;
		}

		static T* allocate( size_t elements, const T& initialValue )
		{
			T* begin_ = reinterpret_cast< T* >( ::operator new( elements * sizeof( value_type )));
			T* end_ = begin_ + elements;

			for( T* p = begin_; p != end_; ++p )
			{
				new( p ) T( initialValue );		// Placement new.
			}

			return begin_;
		}

		static void deallocate( T* p )
		{
			::operator delete( p );
		}

		T* copy( void* dest, void* src, size_t  nBytes )
		{
			T *d = (T *)dest;
			const T *s = (T *)src;

			assert( !( d >= s && d < s + nBytes ) );

			for ( size_t i = 0; i < nBytes; ++i )
			{	
				*( d + i ) = *( s + i );
			}

			return d;
		}

		T* copy_backward( void* dest, void* src, size_t  nBytes )
		{
			T *d = (T *)dest;
			const T *s = (T *)src;

			assert( !( s >= d && s < d + nBytes ) );

			for ( int i = nBytes - 1; i >= 0; --i )
			{
				*( d + i ) = *( s + i );
			}
			return d;
		}

		void destroy( T* start, T* finish )
		{
			size_t n = size_t( finish - start );

			for( size_t i = 0; i < n; ++i )
			{
				( start + i )->~T();
			}
		}
	};
}