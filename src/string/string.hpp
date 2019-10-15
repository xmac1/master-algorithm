
class String {
public:
    String();
    String(char * s);
    ~String();
    int length();
    bool isEmpty();
    void clear();
    String append(const char c);
    String concatenate(const char * s);
    String copy(const char * s);
    String insert(const char c, const int index);
    int find(const char c, const int start);
    String substr(const int s, const int len);
};