#include<iostream>
#include<memory>
#include<string>

using namespace std;

class Query {
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const string&);
    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    string rep() const { return q->rep(); }
private:
    Query(shared_ptr<Query_base> query): q(query) { }
    shared_ptr<Query_base> q;
};

ostream& operator<<(ostream &os, const Query &query){
    return os << query.rep() << endl;
}

