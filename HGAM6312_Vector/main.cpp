#include <iostream>
#include "RVector.h"
#include <vector>

int main()
{
	/*raulroa::Vector<double> point3d( 8 );
	point3d[0] = 2.3;
	point3d[1] = 3.2;
	point3d[2] = 4.2;
	point3d[3] = 3.5;
	point3d[4] = 12.5;
	point3d[5] = 15.5;
	point3d[6] = 14.5;
	point3d[7] = 18.5;


	std::cout << "empty?: " << point3d.empty() << std::endl;
	std::cout << "size: " << point3d.size() << std::endl;
	std::cout << "capacity: " << point3d.capacity() << std::endl;
	std::cout << "max_size: " << point3d.max_size() << std::endl;

	std::cout << "INSERTING!" << std::endl;

	raulroa::Vector<double>::iterator i, j;
	i = point3d.begin();
	j = point3d.end();
	i = point3d.insert( i + 3, 10.0 );

	for(raulroa::Vector<double>::iterator i = point3d.begin(); i != point3d.end(); ++i)
	{
		std::cout << *i << std::endl;
	}
	
	std::cout << "empty?: " << point3d.empty() << std::endl;
	std::cout << "size: " << point3d.size() << std::endl;
	std::cout << "capacity: " << point3d.capacity() << std::endl;
	std::cout << "max_size: " << point3d.max_size() << std::endl;

	std::cout << "STD VECTOR!" <<std::endl;
	
	std::vector<double> points( 8 );
	points[0] = 2.3;
	points[1] = 3.2;
	points[2] = 4.2;
	points[3] = 3.5;
	points[4] = 12.5;
	points[5] = 15.5;
	points[6] = 14.5;
	points[7] = 18.5;


	std::cout << "empty?: " << points.empty() << std::endl;
	std::cout << "size: " << points.size() << std::endl;
	std::cout << "capacity: " << points.capacity() << std::endl;
	std::cout << "max_size: " << points.max_size() << std::endl;

	std::cout << "INSERTING!" << std::endl;

	std::vector<double>::iterator k, m;
	k = points.begin();
	m = points.end();
	k = points.insert( k + 3, 10.0 );

	for(std::vector<double>::iterator i = points.begin(); i != points.end(); ++i)
	{
		std::cout << *i << std::endl;
	}

	std::cout << "empty?: " << points.empty() << std::endl;
	std::cout << "size: " << points.size() << std::endl;
	std::cout << "capacity: " << points.capacity() << std::endl;
	std::cout << "max_size: " << points.max_size() << std::endl;*/

	//raulroa::Vector<double> point3d( 10 );
	//for( int i = 1; i <= 10; ++i )
	//{
	//	point3d[ i - 1 ] = i;
	//}

	//std::cout << "empty?: " << point3d.empty() << std::endl;
	//std::cout << "size: " << point3d.size() << std::endl;
	//std::cout << "capacity: " << point3d.capacity() << std::endl;
	//std::cout << "max_size: " << point3d.max_size() << std::endl;

	//// erase the 6th element
	//point3d.erase ( point3d.begin() + 0 );

	//// erase the first 3 elements:
	//point3d.erase (point3d.begin(),point3d.begin()+3);

	//std::cout << "myvector contains:";
	//for (unsigned i=0; i<point3d.size(); ++i)
	//	std::cout << ' ' << point3d[i];
	//std::cout << '\n';

	//std::cout << "empty?: " << point3d.empty() << std::endl;
	//std::cout << "size: " << point3d.size() << std::endl;
	//std::cout << "capacity: " << point3d.capacity() << std::endl;
	//std::cout << "max_size: " << point3d.max_size() << std::endl;

	//std::cout << "STD VECTOR!" <<std::endl;

	//std::vector<int> myvector;

	//// set some values (from 1 to 10)
	//for (int i=1; i<=10; i++) myvector.push_back(i);

	//std::cout << "empty?: " << myvector.empty() << std::endl;
	//std::cout << "size: " << myvector.size() << std::endl;
	//std::cout << "capacity: " << myvector.capacity() << std::endl;
	//std::cout << "max_size: " << myvector.max_size() << std::endl;

	//// erase the 6th element
	//myvector.erase (myvector.begin()+0);

	//// erase the first 3 elements:
	//myvector.erase (myvector.begin(),myvector.begin()+3);

	//std::cout << "myvector contains:";
	//for (unsigned i=0; i<myvector.size(); ++i)
	//	std::cout << ' ' << myvector[i];
	//std::cout << '\n';

	//std::cout << "empty?: " << myvector.empty() << std::endl;
	//std::cout << "size: " << myvector.size() << std::endl;
	//std::cout << "capacity: " << myvector.capacity() << std::endl;
	//std::cout << "max_size: " << myvector.max_size() << std::endl;

	/*raulroa::Vector<int> mypoints;
	int sum1 (0);
	
	std::cout << "empty?: " << mypoints.empty() << std::endl;
	std::cout << "size: " << mypoints.size() << std::endl;
	std::cout << "capacity: " << mypoints.capacity() << std::endl;
	std::cout << "max_size: " << mypoints.max_size() << std::endl;

	mypoints.push_back (100);
	mypoints.push_back (200);
	mypoints.push_back (300);

	std::cout << "empty?: " << mypoints.empty() << std::endl;
	std::cout << "size: " << mypoints.size() << std::endl;
	std::cout << "capacity: " << mypoints.capacity() << std::endl;
	std::cout << "max_size: " << mypoints.max_size() << std::endl;

	while (!mypoints.empty())
	{
		sum1+=mypoints.back();
		mypoints.pop_back();
	}

	std::cout << "The elements of myvector add up to " << sum1 << '\n';

	std::cout << "empty?: " << mypoints.empty() << std::endl;
	std::cout << "size: " << mypoints.size() << std::endl;
	std::cout << "capacity: " << mypoints.capacity() << std::endl;
	std::cout << "max_size: " << mypoints.max_size() << std::endl;

	std::cout << "==================================================" << std::endl;
	std::cout << "STD VECTOR!" << std::endl;
	std::cout << "==================================================" << std::endl;

	std::vector<int> myvector;
	std::cout << "empty?: " << myvector.empty() << std::endl;
	std::cout << "size: " << myvector.size() << std::endl;
	std::cout << "capacity: " << myvector.capacity() << std::endl;
	std::cout << "max_size: " << myvector.max_size() << std::endl;
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);
	
	std::cout << "empty?: " << myvector.empty() << std::endl;
	std::cout << "size: " << myvector.size() << std::endl;
	std::cout << "capacity: " << myvector.capacity() << std::endl;
	std::cout << "max_size: " << myvector.max_size() << std::endl;

	while (!myvector.empty())
	{
		sum+=myvector.back();
		myvector.pop_back();
	}

	std::cout << "empty?: " << myvector.empty() << std::endl;
	std::cout << "size: " << myvector.size() << std::endl;
	std::cout << "capacity: " << myvector.capacity() << std::endl;
	std::cout << "max_size: " << myvector.max_size() << std::endl;
	
	std::cout << "The elements of myvector add up to " << sum << '\n';*/

//raulroa::Vector<int>::size_type sz;
//
//raulroa::Vector<int> foo;
//sz = foo.capacity();
//std::cout << "making foo grow:\n";
//for (int i=0; i<100; ++i) {
//	foo.push_back(i);
//	if (sz!=foo.capacity()) {
//		sz = foo.capacity();
//		std::cout << "capacity changed: " << sz << '\n';
//	}
//}
//
//raulroa::Vector<int> bar;
//sz = bar.capacity();
//bar.reserve(100);   // this is the only difference with foo above
//std::cout << "making bar grow:\n";
//for (int i=0; i<100; ++i) {
//	bar.push_back(i);
//	if (sz!=bar.capacity()) {
//		sz = bar.capacity();
//		std::cout << "capacity changed: " << sz << '\n';
//	}
//}

//raulroa::Vector<int> myvector;
//
//// set some initial content:
//for (int i=1;i<10;i++) myvector.push_back(i);
//
//myvector.resize(5);
//myvector.resize(8,100);
//myvector.resize(12);
//
//std::cout << "myvector contains:";
//for (int i=0;i<myvector.size();i++)
//	std::cout << ' ' << myvector[i];
//std::cout << '\n';


	raulroa::Vector<int> myvector( 1000 );
	/*for (int i=1;i<10;i++) myvector1.push_back(i);

	raulroa::Vector<int> myvector2 = myvector1;
	myvector2[0] = 12;

	std::cout << "Are the same? " << ( myvector2 == myvector1 ) << std::endl;

	myvector1 = myvector2;
	std::cout << "Are the same? " << ( myvector2 == myvector1 ) << std::endl;

	std::cout << "myvector contains:";
	for (int i=0;i<myvector1.size();i++)
		std::cout << ' ' << myvector1[i];
	std::cout << '\n';

	for (int i=0;i<myvector2.size();i++)
		std::cout << ' ' << myvector2[i];
	std::cout << '\n';
*/

	/*std::cout << "empty?: " << myvector.empty() << std::endl;
	std::cout << "size: " << myvector.size() << std::endl;
	std::cout << "capacity: " << myvector.capacity() << std::endl;
	std::cout << "max_size: " << myvector.max_size() << std::endl;

	myvector.erase( myvector.begin() + 200, myvector.begin() + 600 );

	std::cout << "empty?: " << myvector.empty() << std::endl;
	std::cout << "size: " << myvector.size() << std::endl;
	std::cout << "capacity: " << myvector.capacity() << std::endl;
	std::cout << "max_size: " << myvector.max_size() << std::endl;

	myvector.resize( myvector.size() / 2 );

	std::cout << "empty?: " << myvector.empty() << std::endl;
	std::cout << "size: " << myvector.size() << std::endl;
	std::cout << "capacity: " << myvector.capacity() << std::endl;
	std::cout << "max_size: " << myvector.max_size() << std::endl;

	myvector.clear();

	std::cout << "empty?: " << myvector.empty() << std::endl;
	std::cout << "size: " << myvector.size() << std::endl;
	std::cout << "capacity: " << myvector.capacity() << std::endl;
	std::cout << "max_size: " << myvector.max_size() << std::endl;
*/

	raulroa::Vector<int> myvector2( myvector );

	std::cout << "empty?: " << myvector.empty() << std::endl;
	std::cout << "size: " << myvector.size() << std::endl;
	std::cout << "capacity: " << myvector.capacity() << std::endl;
	std::cout << "max_size: " << myvector.max_size() << std::endl;

	std::cout << "empty?: " << myvector2.empty() << std::endl;
	std::cout << "size: " << myvector2.size() << std::endl;
	std::cout << "capacity: " << myvector2.capacity() << std::endl;
	std::cout << "max_size: " << myvector2.max_size() << std::endl;

	std::cin.get();
	
	return 0;
}