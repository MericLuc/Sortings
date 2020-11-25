/*!
 * @file   sortings.h
 * @brief  Header for home-made implementations of the common sorting algorithms
 * @author lhm
 * @date   15/10/2020
 */

#ifndef SORTINGS_H
#define SORTINGS_H

#include <vector>
#include <algorithm>
#include <cstdint>

namespace SORTINGS {

// ----- Bubble sort ----- //
/*
Complx temporelle
    - worst case   O(n²)
    - average case O(n²)
    - best case    O(n)
Complx spatiale
    - O(1)

    NB : Pas ouf
         Tri en place (pas de tableau auxilliaire )
*/
template< class T >
void bubbleSort_m( std::vector<T>& m )
{
    bool keep(true);
    while( keep )
    {
        keep = false;
        for ( uint32_t i = 0; i < m.size() - 1; i++ )
            if ( m[i] > m[i+1] ) { std::swap(m[i], m[i+1]); keep = true; }
    }
}

template< class T >
std::vector<T> bubbleSort( const std::vector<T>& m )
{
    std::vector<T> v(m);
    bool keep(true);
    while( keep )
    {
        keep = false;
        for ( uint32_t i = 0; i < v.size() - 1; i++ )
            if ( v[i] > v[i+1] ) { std::swap(v[i], v[i+1]); keep = true; }
    }
    return v;
}

// ----- Insertion sort ----- //
/*
Complx temporelle
    - worst case   O(n²)
    - average case O(n²)
    - best case    O(n)
Complx spatiale
    - O(1)

    NB : Très bon sur des entrées de petite taille et/ou des
         données presque triées.
         Tri stable (conserve l'ordre d'apparition des élems égaux )
         Tri en place (pas de tableau auxilliaire )
*/
template< class T >
void insertionSort_m( std::vector<T>& m )
{
    for ( uint32_t i = 0; i < m.size(); i++ )
    {
        int j(i);
        while( j > 0 && m[j-1] > m[j] ) { std::swap( m[j], m[j-1] ); --j; }
    }
}

template< class T >
std::vector<T> insertionSort( const std::vector<T>& m )
{
    std::vector<T> v(m);
    for ( uint32_t i = 0; i < v.size(); i++ )
    {
        int j(i);
        while( j > 0 && v[j-1] > v[j] ) { std::swap( v[j], v[j-1] ); --j; }
    }
    return v;
}

// ----- Selection sort ----- //
/*
Complx temporelle
    - worst case   O(n²)
    - average case O(n²)
    - best case    O(n²)
Complx spatiale
    - O(1)

    NB : Vraiment pas ouf - temps quadratique et non pseudo linéaire
         comme les précédents.
*/
template< class T >
std::vector<T> selectionSort( const std::vector<T>& m )
{
    std::vector<T> v(m);
    for ( uint32_t i = 0; i < v.size() - 1; i++ )
    {
        int min(i);
        for ( int j = i + 1; j < v.size(); j++ )
            if ( v[j] < v[min] ) { min = j; }
        if ( min != i ) { std::swap( v[i], v[min] ); }
    }
    return v;
}

template< class T >
void selectionSort_m( std::vector<T>& m )
{
    for ( uint32_t i = 0; i < m.size() - 1; i++ )
    {
        int min(i);
        for ( uint32_t j = i + 1; j < m.size(); j++ )
            if ( m[j] < m[min] ) { min = j; }
        if ( min != i ) { std::swap( m[i], m[min] ); }
   }
}

// ----- Quick sort ----- //
/*
Complx temporelle
    - worst case   O(n²)
    - average case O(nlog(n))
    - best case    O(nlog(n))
Complx spatiale
    - Pire cas O(n)
    - Moyenne  O(log(n))
*/
template< class T >
void quickSort_m( std::vector<T>& m, int st = 0, int ed = -1 )
{
    if ( ed == -1 ) { ed = m.size() - 1; }
    if ( st >= ed ) { return; }

    int pvt(st), L(st+1), R(ed);

    while( R >= L )
    {
        if ( m.at(L) >  m.at(pvt) &&
               m.at(R) <  m.at(pvt)  ) { std::swap( m[L], m[R] ); }
        if ( m.at(L) <= m.at(pvt)  ) { L++; }
        if ( m.at(R) >= m.at(pvt)  ) { R--; }
    }
    std::swap( m[pvt], m[R] );

    if ( R - 1 - st < ed - R - 1 )
    {
        quickSort_m(m, st , R-1);
        quickSort_m(m, R+1, ed );
    }
    else
    {
        quickSort_m(m, R+1, ed );
        quickSort_m(m, st , R-1);
    }
}

} // Namespace SORTINGS

#endif // SORTINGS_H
