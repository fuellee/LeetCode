#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v);

template <typename keyT, typename valT>
std::ostream &operator<<(std::ostream &out, const std::map<keyT,valT> &m);
template <typename keyT, typename valT>
std::ostream &operator<<(std::ostream &out, const std::unordered_map<keyT,valT> &m);

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::set<T> &s);
template <typename T>
std::ostream &operator<<(std::ostream &out, const std::unordered_set<T> &s);

template <typename T>
void operator+=(std::vector<T> &v1, const std::vector<T> &v2) {
    v1.insert(v1.end(), v2.begin(), v2.end());
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
    if(v.size()==0) {
        out<<"[]";
        return out;
    }
    out<<"[";
    auto it=v.begin();
    out<<*it++;
    for (; it!=v.end(); ++it) out<<", "<<*it;
    out<<"]";
    return out;
}

template <typename keyT, typename valT>
std::ostream &operator<<(std::ostream &out, const std::map<keyT,valT> &m) {
    if(m.size()==0) {
        out<<"{}";
        return out;
    }
    out<<"{";
    auto it=m.begin();
    out<<it->first<<":"<<it->second; ++it;
    for (; it!=m.end(); ++it) out<<", "<<it->first<<":"<<it->second;
    out<<"}";
    return out;
}
template <typename keyT, typename valT>
std::ostream &operator<<(std::ostream &out, const std::unordered_map<keyT,valT> &m) {
    if(m.size()==0) {
        out<<"{}";
        return out;
    }
    out<<"{";
    auto it=m.begin();
    out<<it->first<<":"<<it->second; ++it;
    for (; it!=m.end(); ++it) out<<", "<<it->first<<":"<<it->second;
    out<<"}";
    return out;
}


template <typename T>
std::ostream &operator<<(std::ostream &out, const std::set<T> &s) {
    if(s.size()==0) {
        out<<"{}";
        return out;
    }
    out<<"{";
    auto it=s.begin();
    out<<*it++;
    for (; it!=s.end(); ++it) out<<", "<<*it;
    out<<"}";
    return out;
}
template <typename T>
std::ostream &operator<<(std::ostream &out, const std::unordered_set<T> &s) {
    if(s.size()==0) {
        out<<"{}";
        return out;
    }
    out<<"{";
    auto it=s.begin();
    out<<*it++;
    for (; it!=s.end(); ++it) out<<", "<<*it;
    out<<"}";
    return out;
}
