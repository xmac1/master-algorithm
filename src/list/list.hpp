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

template <typename T>
class ArrList : public List<T> {
private:
    T* data;
    int maxSize;
    int curLen;
    int index;
public:
    ArrList(const int size) {
        maxSize = size;
        data = new T[maxSize];
        curLen = 0;
        index = 0;
    }
    ~ArrList(){delete [] data;}

    void clear() {
        delete [] data;
        data = new T[maxSize];
        curLen = index = 0;
    }

    int length();
    bool append(const T value);
    bool insert(const int p, const T value);
    bool Delete(const int p);
    bool getValue(const int p, T& value);
    bool setValue(const int p, const T value);
    bool getPos(int &p, const T value);
};

template <typename T>
bool ArrList<T>::Delete(const int p) {
    if (p < 0 || p >= curLen) {
        return false;
    }
}

template <typename T>
bool ArrList<T>::getPos(int &p, const T value){
    for (int i = 0; i < curLen; i++) {
        if (value == data[i]) {
            p = i;
            return true;
        }
    }
    return false;
}

template <typename T>
bool ArrList<T>::insert(const int p, const T value) {
    if (p < 0 || p >= maxSize) {
        return false;
    }
    if (curLen >= maxSize) {
        return false;
    }
    for (int i = curLen; i > p; i--) {
        data[i] = data[i-1]; // 向右移动元素
    }
    data[p] = value;
    curLen++;
    return true;
}

template <typename T>int ArrList<T>::length() {
    return this->curLen;
}