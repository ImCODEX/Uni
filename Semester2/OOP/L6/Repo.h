#pragma once
#include <vector>
#include <algorithm>
#include "Cars.h"
#include "Users.h"
#include "CRUD_Repository.h"
using std::vector;
//subclass of crud_repo
namespace Repository{
class Repo : public CrudRepository<Domain::Car>{//Car_Repo_In_Mem
    private:
        vector<Domain::Car> elems;
        int id_new_elem;
    public:
        Repo();
        const int GetSize() const;
        vector<Domain::Car> Get_array() const;
        int pos_by_id(const int find_id) const;
        const Domain::Car &search_by_id(const int find_id) const;
        void add(Domain::Car &);//gives its own id
        //to-do: void add(const Domain::Car x); _default -1 id, modify after
        void update(const Domain::Car &new_car);
        void remove(const int find_id);
        //void read_from_persistent(optional:Filename);
        //void write_to_persistent();
};

class UserRepo : public CrudRepository<Domain::User>{
    private:
        vector<Domain::User> elems;
    public:
        UserRepo();
        vector<Domain::User> Get_array() const;
        void add(Domain::User &new_user);
        void update(const Domain::User &new_user);
        void remove(const int find_id);
        const Domain::User &search_by_id(const int find_id) const;
        const int pos_by_username(const string find_username) const;
        //const Domain::User &search_by_username(const string find_username) const;
        //void remove(const string del_username);
};
}