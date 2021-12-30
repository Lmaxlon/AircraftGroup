#pragma once

#include <memory>
template <class T>
        class new_iterator;
template <class T>
        class new_vector {
        private:
            const static int min_cap = 4;
            T* n_buff;
            std::allocator<T> n_alloc;
            size_t n_capacity;
            size_t n_s;
        public:
            friend class new_iterator<T>;
            typedef new_iterator<T> iterator;
            new_vector() :n_s(0), n_capacity(min_cap), n_buff(n_alloc.allocate(min_cap)) {}
            new_vector(const new_vector<T>&);
            new_vector(new_vector<T>&&);
            ~new_vector();
            new_vector<T>& operator =(const new_vector<T>&);
            new_vector<T>& operator =(new_vector<T>&&);
            const T& operator [](int i) const;
            T& operator [](int i);
            size_t size() const { return n_s; }
            bool empty() { return !n_s; }
            new_iterator<T> begin() const { return new_iterator<T>(n_buff); }
            new_iterator<T> end() const {return new_iterator<T>(n_buff + n_s);}
            T& front(){return n_buff[0];}
            T& back(){return n_buff[n_s - 1];}
            void resize(size_t);
            void push_back(const T&);
            void push_back(T&&);
            void pop_back();
            new_iterator<T> erase(new_iterator<T>);
            size_t erase(size_t position);
            void clear();
        };
template <class T>
        new_vector<T>::new_vector(const new_vector<T>& a) {
            n_buff = n_alloc.allocate(a.n_capacity);
            n_s = a.n_s;
            for (size_t i = 0; i < n_s; i++)
                n_buff[i] = a.n_buff[i];
        }

        template <class T>
                new_vector<T>::new_vector(new_vector<T>&& a) {
                    n_buff = a.n_buff;
                    n_s = a.n_s;
                    n_capacity = a.n_capacity;
                }

                template <class T>
                        new_vector<T>::~new_vector() {
                            if (n_capacity > 0)
                                n_alloc.deallocate(n_buff, n_capacity);
                        }
                        template <class T>
                                new_vector<T>& new_vector<T>::operator =(const new_vector<T>& a) {
                                    resize(a.n_capacity);
                                    std::copy(a.begin(), a.end(), n_buff);
                                    return *this;
                                }

                                template <class T>
                                        new_vector<T>& new_vector<T>::operator =(new_vector<T>&& a) {
                                            T* buf = n_buff;
                                            int sbuf = n_s, scap = n_capacity;
                                            n_buff = a.n_buff;
                                            n_capacity = a.n_capacity;
                                            n_s = a.n_s;
                                            a.n_buff = buf;
                                            a.n_capacity = scap;
                                            a.n_s = sbuf;
                                            return *this;
                                        }
                                        template <class T>
                                                const T& new_vector<T>::operator[](int i) const {
                                                    if (i < 0 || i >= n_s)
                                                        throw std::runtime_error("Wrong index!");
                                                    return n_buff[i];
                                                }

                                                template <class T>
                                                        T& new_vector<T>::operator[](int i) {
                                                            if (i < 0 || i >= n_s)
                                                                throw std::runtime_error("Wrong index!");
                                                            return n_buff[i];
                                                        }
                                                        template <class T>
                                                                void new_vector<T>::resize(size_t new_capacity) {
                                                                    if (new_capacity != n_capacity) {
                                                                        n_capacity = new_capacity;
                                                                        T* buf = n_buff;
                                                                        n_buff = n_alloc.allocate(new_capacity);
                                                                        if (n_s > new_capacity)
                                                                            n_s = new_capacity;
                                                                        for (size_t i = 0; i < n_s; i++)
                                                                            n_buff[i] = std::move(buf[i]);
                                                                        delete[] buf;
                                                                    }
                                                                }

                                                                template <class T>
                                                                        void new_vector<T>::push_back(const T& val) {
                                                                            if (n_capacity == n_s)
                                                                                resize(n_capacity + min_cap);
                                                                            n_buff[n_s] = val;
                                                                            n_s++;
                                                                        }

                                                                        template <class T>
                                                                                void new_vector<T>::push_back(T&& a) {
                                                                                    if (n_capacity == n_s)
                                                                                        resize(n_capacity + min_cap);
                                                                                    n_buff[n_s] = std::move(a);
                                                                                    n_s++;
                                                                                }
                                                                                template <class T>
                                                                                        void new_vector<T>::pop_back() {
                                                                                            n_s--;
                                                                                        }

                                                                                        template <class T>
                                                                                                new_iterator<T> new_vector<T>::erase(new_iterator<T> position) {
                                                                                                    for (new_iterator<T> i = position; i != end() - 1; i++) {
                                                                                                        *i = *(i + 1);
                                                                                                    }
                                                                                                    n_s--;
                                                                                                    return position;
                                                                                                }

                                                                                                template <class T>
                                                                                                        size_t new_vector<T>::erase(size_t position) {
                                                                                                            n_s--;
                                                                                                            for (size_t i = position; i < n_s; i++) {
                                                                                                                n_buff[i] = n_buff[i + 1];
                                                                                                            }
                                                                                                            return position;
                                                                                                        }

                                                                                                        template <class T>
                                                                                                                void new_vector<T>::clear() {
                                                                                                                    if (n_capacity > 0) {
                                                                                                                        n_alloc.deallocate(n_buff, n_capacity);
                                                                                                                        n_s = 0;
                                                                                                                        n_capacity = 0;
                                                                                                                    }
                                                                                                                }
                                                                                                                template <class T>
                                                                                                                        class new_iterator {
                                                                                                                        private:
                                                                                                                            T* n_it;
                                                                                                                        public:
                                                                                                                            new_iterator() :n_it(0) {}
                                                                                                                            new_iterator(T* a) :n_it(a) {}
                                                                                                                            new_iterator(const new_iterator<T>& p) { n_it = p.n_it; }
                                                                                                                            ~new_iterator() {}
                                                                                                                            new_iterator<T> operator +(const size_t) const;
                                                                                                                            new_iterator<T> operator -(const size_t) const;
                                                                                                                            new_iterator<T>& operator +=(const size_t);
                                                                                                                            new_iterator<T>& operator -=(const size_t);
                                                                                                                            new_iterator<T>& operator ++();
                                                                                                                            new_iterator<T> operator ++(int);
                                                                                                                            bool operator <(const new_iterator<T> a) const { return n_it < a.n_it; }
                                                                                                                            bool operator >(const new_iterator<T> a) const { return n_it > a.n_it; }
                                                                                                                            bool operator <=(const new_iterator<T> a) const { return n_it <= a.n_it; }
                                                                                                                            bool operator >=(const new_iterator<T> a) const { return n_it >= a.n_it; }
                                                                                                                            bool operator !=(const new_iterator<T> a) const { return n_it != a.n_it; }
                                                                                                                            bool operator ==(const new_iterator<T> a) const { return n_it == a.n_it; }
                                                                                                                            T& operator *() { return *n_it; }
                                                                                                                            T* operator ->() { return n_it; }
                                                                                                                        };

template <class T>
        new_iterator<T> new_iterator<T>::operator +(const size_t i) const {
            new_iterator<T> res(*this);
            res.n_it += i;
            return res;
        }

        template <class T>
                new_iterator<T> new_iterator<T>::operator -(const size_t i) const {
                    new_iterator<T> res(*this);
                    res.n_it -= i;
                    return res;
                }

                template <class T>
                        new_iterator<T>& new_iterator<T>::operator +=(const size_t i) {
                            n_it += i;
                            return *this;
                        }

                        template <class T>
                                new_iterator<T>& new_iterator<T>::operator -=(const size_t i) {
                                    n_it -= i;
                                    return *this;
                                }

                                template <class T>
                                        new_iterator<T>& new_iterator<T>::operator ++() {
                                            n_it++;
                                            return *this;
                                        }

                                        template <class T>
                                                new_iterator<T> new_iterator<T>::operator ++(int) {
                                                    new_iterator<T> res(*this);
                                                    n_it++;
                                                    return res;
                                                }
