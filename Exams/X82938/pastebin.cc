#include <iostream>
#include <vector>
using namespace std;

int find_unimodal(const vector<int>& v,int i,int j) {
    if (j-i == 0) return j;
    if (j-i == 1) {
        if (v[j] > v[i]) return j;
        return i;
    }
    int mid = (i+j) / 2;
    if (v[mid-1] < v[mid] and v[mid] < v[mid+1]) return find_unimodal(v,mid+1,j);
    if (v[mid-1] > v[mid] and v[mid] > v[mid+1]) return find_unimodal(v,i,mid-1);
    return mid;
}

bool d_search(const vector<int>& v, int x, int i, int j) {
    if (j >= i) {
        int mid = (j+i)/2;
        if (v[mid] == x) return true;
        if (v[mid] < x) return d_search(v,x,mid+1,j);
        return d_search(v,x,i,mid-1);
    }
    return false;
}

bool id_search(const vector<int>& v, int x, int i, int j) {
    if (j >= i) {
        int mid = (j+i)/2;
        if (v[mid] == x) return true;
        if (x < v[mid]) return id_search(v,x,mid+1,j);
        return id_search(v,x,i,mid-1);
    }
    return false;
}

bool search(int x, const vector<int>& v) {
    int pos = find_unimodal(v,0,v.size()-1); //we'll always find an unimodal(pre)
    if (d_search(v,x,0,pos)) return true;
    if (id_search(v,x,pos,v.size()-1)) return true;
    return false;
}
