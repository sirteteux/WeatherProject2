//map.h
#ifndef MAP_H
#define MAP_H
//-------------------------------------------------------------------------------------------
// Includes

#include <map>

/**
* @class Map
* @brief Encapsulates std::map
*
* @author Andreas Lau
* @version 01
* @date 07/04/2021, Andreas started
*
* @bug I may be wrong but there is no bugs at the moment.
*/

template <class Key, class T>
class Map
{
    public:
        /**
        * @brief Default constructor
        */
        Map();

        /**
        * @brief Overloaded constructor
        *
        * @param Key and value
        */
        Map(T first, T last);

        /**
        * @brief adds to the map
        *
        * @param the key and the value
        */
        void Add(Key key, T value);

        /**
        * @brief gets the value at the specified key
        *
        * @param Key
        *
        * @return the value
        */
        T GetAt(Key key);

        /**
        * @brief returns iterator at beginning of map
        *
        * @return iterator at beginning of map
        */
        typename std::map<Key, T>::iterator ItBegin();

        /**
        * @brief returns iterator at end of map
        *
        * @return iterator at end of map
        */
        typename std::map<Key, T>::iterator ItEnd();

        /**
        * @brief returns current iterator of map
        *
        * @return current iterator of map
        */
        typename std::map<Key, T>::iterator& GetIt();

        /**
        * @brief returns size of map
        *
        * @return size of map
        */
        int GetSize();

        /**
        * @brief overloaded [] operator
        *
        * @param key
        *
        * @return Reference to map value at key
        */
        T& operator[](Key &&key);

    private:
        std::map<Key, T> m_map;
        typename std::map<Key, T>::iterator m_iterator;
};

//-------------------------------------------------------------------------------------------
// Implementations

template <class Key, class T>
Map<Key, T>::Map()
    : m_map(), m_iterator() {}

template <class Key, class T>
Map<Key, T>::Map(T first, T last)
    : m_map(first, last) {}

template <class Key, class T>
void Map<Key, T>::Add(Key key, T value)
{
    m_map[key] = value;
}

template <class Key, class T>
T Map<Key, T>::GetAt(Key key)
{
    return(m_map.at(key));
}


template <class Key, class T>
typename std::map<Key, T>::iterator Map<Key, T>::ItBegin()
{
    return(m_map.begin());
}

template <class Key, class T>
typename std::map<Key, T>::iterator Map<Key, T>::ItEnd()
{
    return(m_map.end());
}

template <class Key, class T>
typename std::map<Key, T>::iterator& Map<Key, T>::GetIt()
{
    return(m_iterator);
}

template <class Key, class T>
int Map<Key, T>::GetSize()
{
    return(m_map.size());
}

template <class Key, class T>
T& Map<Key, T>::operator[](Key &&key)
{
    return(m_map[key]);
}

#endif
