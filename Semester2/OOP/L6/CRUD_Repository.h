#pragma once
#include<vector>
using std::vector;

/**
* CREATE, READ, UPDATE, DELETE
* CRUD operations repository interface
*/
template <class E>
class CrudRepository
{
public:
    /**
    * @param id -the id of the entity to be returned id must not be null
    * @return the entity with the specified id or null - if there is no entity with the given id
    *
    */
    const virtual E &search_by_id(const int id) const = 0;

    /**
    * @return all entities
    */
    virtual vector<E> Get_array() const = 0;

    /**
    * @param entity entity must be not null
    * @return null- if the given entity is saved otherwise returns the entity (id already exists)
    *
    */
    virtual void add(E &) = 0;

    /**
    * removes the entity with the specified id
    *
    * @param id id must be not null
    * @return the removed entity or null if there is no entity with the given id
    *
    */
    virtual void remove(const int id) = 0;

    /**
    * @param entity entity must not be null
    * @return null - if the entity is updated, otherwise returns the entity - (e.g id does not exist).
    *
    */
    virtual void update(const E &entity) = 0;

    virtual ~CrudRepository(){};
};
