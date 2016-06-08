//
// Created by szuyev on 25.05.16.
//

#pragma once

#include <array>

namespace zzsystems { namespace gorynych {

    template<typename T, size_t N, size_t M>
    struct alignas(alignof(T)) mat
    {
        static_assert(N * M > 0, "Wrong dimensions for a matrix");

        std::array<T, N * M> data;

        mat() = default;

        mat(std::initializer_list<T> data) : data(data)
        {}

        mat(std::initializer_list<mat<T, N, 1>> data)
        {
            for(int row = 0; row < M; row++)
            {
                for(int col = 0; col < N; col++)
                {
                    this->operator[](col, row) = data[col][row];
                }
            }
        }

        mat(std::initializer_list<mat<T, 1, M>> data) : data(data)
        {
            for(int row = 0; row < M; row++)
            {
                for(int col = 0; col < N; col++)
                {
                    this->operator[](col, row) = data[row][col];
                }
            }
        }

        mat(const std::array<T> &data) : data(data)
        {}

        mat(std::array<T>&& data)
        {
            std::move(rhs.data, data);
        }

        mat(const T* data) : data(data)
        {}

        mat(mat&& rhs)
        {
            std::move(rhs.data, data);
        }

        inline T operator[](int col, int row)
        {
            return data[row * N + col];
        }

        /*inline mat<T, N, 1> operator[](int col)
        {
            mat<T, N, 1> result;

            for(int row = 0; row < M; row++)
            {
                result[]
                    this->operator[](col, row) = data[col][row];
                }
            }


            return mat<T, N, 1>(
                    {
                            data[]
                    };)
        }*/
    };

    template<typename T, size_t N, size_t M>
    mat<T, N, M> operator+(const mat<T, N, M>& a, const mat<T, N, M>& b)
    {
        mat<T, N, M> result;

        for(int k = 0; k < M; k++)
        {
            for(int j = 0; j < N; k++)
            {
                result[j, k] = a[j, k] +  b[j, k];
            }
        }

        return result;
    };

    template<typename T, size_t N, size_t M>
    mat<T, N, M> operator-(const mat<T, N, M>& a, const mat<T, N, M>& b)
    {
        mat<T, N, M> result;

        for(int k = 0; k < M; k++)
        {
            for(int j = 0; j < N; k++)
            {
                result[j, k] = a[j, k] - b[j, k];
            }
        }

        return result;
    };

    template<typename T, size_t N, size_t M>
    mat<T, N, M> operator+(const mat<T, N, M>& a, const T& b)
    {
        mat<T, N, M> result;

        for(int k = 0; k < M; k++)
        {
            for(int j = 0; j < N; k++)
            {
                result[j, k] = a[j, k] + b;
            }
        }

        return result;
    };

    template<typename T, size_t N, size_t M>
    mat<T, N, M> operator-(const mat<T, N, M>& a, const T& b)
    {
        mat<T, N, M> result;

        for(int k = 0; k < M; k++)
        {
            for(int j = 0; j < N; k++)
            {
                result[j, k] = a[j, k] - b;
            }
        }

        return result;
    };

    template<typename T, size_t N, size_t M>
    mat<T, N, M> operator*(const mat<T, N, M>& a, const T& b)
    {
        mat<T, N, M> result;

        for(int k = 0; k < M; k++)
        {
            for(int j = 0; j < N; k++)
            {
                result[j, k] = a[j, k] * b;
            }
        }

        return result;
    };

    template<typename T, size_t N, size_t M>
    mat<T, N, M> operator/(const mat<T, N, M>& a, const T& b)
    {
        mat<T, N, M> result;

        for(int k = 0; k < M; k++)
        {
            for(int j = 0; j < N; k++)
            {
                result[j, k] = a[j, k] / b;
            }
        }

        return result;
    };

    template<typename T, size_t N, size_t M, size_t N2>
    mat<T, N, M> operator*(const mat<T, N, M>& a, const mat<T, M, N2>& b)
    {
        mat<T, N, N2> result;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N2; j++) {

                T temp = a.data[i * n] * b.data[j];

                for (int k = 1; k < N; k++) {
                    temp += a[i, k] * a[k, j];
                }

                result[i, j] = temp;
            }
        }

        return result;
    };



    template<typename T>
    using mat2x2 = mat<T, 2, 2>;

    template<typename T>
    using mat3x2 = mat<T, 3, 2>;

    template<typename T>
    using mat2x3 = mat<T, 2, 3>;

    template<typename T>
    using mat3x3 = mat<T, 3, 3>;


    template<typename T>
    using vec2 = mat<T, 2, 1>;

    template<typename T>
    using vec3 = mat<T, 3, 1>;

    template<typename T>
    using scalar = mat<T, 1, 1>;

}}