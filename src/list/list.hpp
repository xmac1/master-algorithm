#ifndef __LIST__
#define __LIST__

template <typename T>
class List {
public:
    void clear();
    bool isEmpty();
    bool append(const T value);
    bool insert(const int p, const T value);
    bool Delete(const int p);
    bool getValue(const int p, T& value);
    bool setValue(const int p, const T value);
    bool getPos(int &p, const T value);
};

#endif // ifndef __LIST__