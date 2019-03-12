#include <string>

#ifndef DEFINE_TEMPLATE_STACK
#define DEFINE_TEMPLATE_STACK

template <typename T> class Stack
{
public:
	Stack(size_t s = 1024);
   ~Stack();

    class Exception
    {
        std::string message;
    public:
        Exception(const std::string& s = std::string() ) :
            message("Exception.")
        {
            message.append(s);
        }
    };

    class Badsize : public Exception
    {
    public:
        Badsize() : Exception("StackBadsize.") {}
    };
    class Underflow : public Exception
    {
    public:
        Underflow() : Exception("StackUnderflow.") {}
    };
    class Overflow : public Exception
    {
    public:
        Overflow() : Exception("StackOverflow.") {}
    };
	
	void Push(T);
	T Pop();

	size_t Length();
	size_t Total();
    
private:
    static const size_t max = 10000;

	T* value;
	size_t size, top;
    
};

template <typename T> Stack<T>::Stack(size_t s)
{
    value = 0;
    size = top = 0;
    
    if (s > max) throw Badsize();
    value = new T[s];

    size = s;
    top = 0;
}
template <typename T> Stack<T>::~Stack()
{
    delete[] value;

    value = 0;
    size = top = 0;
}

template <typename T> void Stack<T>::Push(T p)
{
    if (top == size) throw Overflow();

    value[top] = p;
    top++;
}
template <typename T> T Stack<T>::Pop()
{
    if (top == 0) throw Underflow();

    top--;
    return value[top];
}

inline template <typename T> size_t Stack<T>::Length()
{
    return size;
}
inline template <typename T> size_t Stack<T>::Total()
{
    return top;
}

#endif