
#ifndef __STACK_HPP__
# define __STACK_HPP__

# include "vector.hpp"

namespace ft
{
    template< class T,class Container = ft::vector<T> >
    class stack
    {
public:
/*
** Public Member Types: ***************************************************************************
*/
    typedef          Container                   container_type;
    typedef typename Container::value_type       value_type;
    typedef typename Container::size_type        size_type;
    typedef typename Container::reference        reference;
    typedef typename Container::const_reference  const_reference;
/*
** Public Methods: ********************************************************************************
*/
public:
/*
** Member functions: ******************************************************************************
*/
    explicit stack( const Container& cont = Container() ) : __container(cont) { return ; }

    ~stack( void ) { return ; }

    stack& operator=( const stack& other )
    {
        if (this != &other)
            this->__container = other.__container;
        return *this;
    }
/*
** Element access: ********************************************************************************
*/
    reference top()
    { return *this->__container.rbegin(); }

    const_reference top() const
    { return *this->__container.rbegin(); }

    bool empty() const
    { return this->__container.empty(); }

    size_type size() const
    { return this->__container.size(); }

    void push( const value_type& value )
    { this->__container.push_back(value); }

    void pop()
    { this->__container.pop_back(); }
/*
** Friends functions: *****************************************************************************
*/
    template <class FT, class FTContainer>
        friend bool operator==( const stack<FT,FTContainer>& lhs, const stack<FT,FTContainer>& rhs );

    template <class FT, class FTContainer>
        friend bool operator!=( const stack<FT,FTContainer>& lhs, const stack<FT,FTContainer>& rhs );

    template <class FT, class FTContainer>
        friend bool operator<( const stack<FT,FTContainer>& lhs, const stack<FT,FTContainer>& rhs );

    template <class FT, class FTContainer>
        friend bool operator<=( const stack<FT,FTContainer>& lhs, const stack<FT,FTContainer>& rhs );

    template <class FT, class FTContainer>
        friend bool operator>( const stack<FT,FTContainer>& lhs, const stack<FT,FTContainer>& rhs );

    template <class FT, class FTContainer>
        friend bool operator>=( const stack<FT,FTContainer>& lhs, const stack<FT,FTContainer>& rhs );
/*
** Protected Attributes: **************************************************************************
*/
    protected:
        container_type  __container;
    };  // Class Stack;

/*
** Non-member functions: **************************************************************************
*/
    template< class T, class Container >
    bool operator==( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
    { return  lhs.__container == rhs.__container; }

    template< class T, class Container >
    bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
    { return  lhs.__container != rhs.__container; }

    template< class T, class Container >
    bool operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
    { return  lhs.__container < rhs.__container; }

    template< class T, class Container >
    bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
    { return  lhs.__container <= rhs.__container; }

    template< class T, class Container >
    bool operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
    { return  lhs.__container > rhs.__container; }

    template< class T, class Container >
    bool operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
    { return  lhs.__container >= rhs.__container; }
};  // Namespace FT;

#endif
