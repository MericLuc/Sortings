/*!
 * @file   vectors_utility.h
 * @brief  Utility functions that can be usefull when working on std::vector<T>
 * @author lhm
 * @date   15/10/2020
 */

#ifndef VECTORS_UTILITIES_H
#define VECTORS_UTILITIES_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

namespace SORTINGS {

template < class T >
std::string toString(const std::vector<T>& v, std::string delim = ", " )
{
    std::stringstream ss;
    std::copy( std::begin(v), std::end(v), std::ostream_iterator<T>(ss, delim.c_str()) );
    std::string l_ret( ss.str() );

    return l_ret.size() > delim.size() ? std::string(l_ret.begin(), l_ret.end()-delim.size() ) : l_ret;
}

template < class T >
void toCout(const std::vector<T>& v, std::string delim = ", " )
{
    std::stringstream ss;
    std::copy( std::begin(v), std::end(v), std::ostream_iterator<T>(std::cout, delim.c_str()) );
    std::cout << std::endl;
}

template<typename RandomIterator>
void toCout(RandomIterator begin, RandomIterator end, std::string delim = ", ")
{
   typedef typename std::iterator_traits<RandomIterator>::value_type T;

    std::stringstream ss;
    std::copy( begin, end, std::ostream_iterator<T>(std::cout, delim.c_str()) );
    std::cout << std::endl;
}

template<typename RandomIterator>
std::string toString(RandomIterator begin, RandomIterator end, std::string delim = ", ")
{
   typedef typename std::iterator_traits<RandomIterator>::value_type T;

   std::stringstream ss;
   std::copy( begin, end, std::ostream_iterator<T>(ss, delim.c_str()) );
   std::string l_ret( ss.str() );

   return l_ret.size() > delim.size() ? std::string(l_ret.begin(), l_ret.end()-delim.size() ) : l_ret;
}

} // Namespace SORTINGS

#endif // VECTORS_UTILITIES_H
