//
// Created by yyd on 2025/12/24.
//

#ifndef UNTITLED_VEXCOMPUTE_H
#define UNTITLED_VEXCOMPUTE_H
#include <array>
#include <cstdint>
struct Vec3;
struct Vec2;

struct Vec3 {
    float x, y, z;

    Vec3 operator + (const Vec3 &other) const;
    Vec3 operator - (const Vec3 &other) const;
    Vec3 operator * (float scalar) const;
    Vec3 operator / (float scalar) const;

    float operator * (const Vec3 &other) const;

    bool operator == (const Vec3 &other) const;
    bool operator > (float scalar) const;
};

struct Vec2 {
    float x, y;

};


template<size_t N>
struct VecN {
    std::array<float, N> data;

    VecN() {data.fill(0.0f);}

    explicit VecN(float scalar) {data.fill(scalar);}

    explicit VecN(float *arr) {
        std::copy(arr, arr + N, data.begin());
    }

    static float getN();


    float operator[] (size_t index) const;
    VecN operator + (const VecN &other) const;
    VecN operator - (const VecN &other) const;
    VecN operator * (float scalar) const;
    float operator * (const VecN &other) const;
    VecN operator / (float scalar) const;
    bool operator == (const VecN &other) const;
    bool operator > (float scalar) const;

};


// Vec3版本
float getLength(const Vec3 &a);
float dot(const Vec3 &a, const Vec3 &b);
float cosAngle(const Vec3 &a, const Vec3 &b);

bool sameDirection(const Vec3 &a, const Vec3 &b);
bool inLeft(const Vec3 &a, const Vec3 &b);

Vec3 project(const Vec3 &a, const Vec3 &b);
Vec3 cross(const Vec3 &a, const Vec3 &b);
Vec3 normalize(const Vec3 &a);


// 通用泛型
template<size_t N>
float getLength(const VecN<N> &a);

template<size_t N>
float dot(const VecN<N> &a, const VecN<N> &b);

template<size_t N>
float cosAngle(const VecN<N> &a, const VecN<N> &b);

template<size_t N>
bool sameWay(const VecN<N> &a, const VecN<N> &b);

template<size_t N>
bool inLeft(const VecN<N> &a, const VecN<N> &b);

template<size_t N>
bool inRight(const VecN<N> &a, const VecN<N> &b);

template<size_t N>
VecN<N> project(const VecN<N> &a, const VecN<N> &b);

template<size_t N>
VecN<N> cross(const VecN<N> &a, const VecN<N> &b);

template<size_t N>
VecN<N> normalize(const VecN<N> &a);
#endif //UNTITLED_VEXCOMPUTE_H