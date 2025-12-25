//
// Created by yyd on 2025/12/24.
//
#include "VexCompute.h"

#include <cmath>
#include <iostream>
#include <ostream>


Vec3 Vec3::operator+ (const Vec3 &other) const {
    Vec3 result{};
    result.x = this->x + other.x;
    result.y = this->y + other.y;
    result.z = this->z + other.z;
    return result;
}

Vec3 Vec3::operator- (const Vec3 &other) const {
    Vec3 result{};
    result.x = this->x - other.x;
    result.y = this->y - other.y;
    result.z = this->z - other.z;
    return result;
}

Vec3 Vec3::operator* (const float scalar) const {
    Vec3 result{};
    result.x = this->x * scalar;
    result.y = this->y * scalar;
    result.z = this->z * scalar;
    return result;
}

float Vec3::operator* (const Vec3 &other) const {
    return this->x * other.x + this->y * other.y + this->z * other.z;
}

Vec3 Vec3::operator/ (const float scalar) const {
    Vec3 result{};
    result.x = this->x / scalar;
    result.y = this->y / scalar;
    result.z = this->z / scalar;
    return result;
}

bool Vec3::operator== (const Vec3 &other) const {
    return this->x == other.x && this->y == other.y && this->z == other.z;
}

bool Vec3::operator > (const float scalar) const {
    return this->x > scalar && this->y > scalar && this->z > scalar;
}


// Vec3 版本
// 获取长度
float getLength(const Vec3 &a) {
    return std::sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

// 内积
float dot(const Vec3 &a, const Vec3 &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// cos theta
float cosAngle(const Vec3 &a, const Vec3 &b) {
    const float lenA = getLength(a);
    if (const float lenB = getLength(b); lenA == 0 || lenB == 0) return INFINITY;
    return a * b / (getLength(a) * getLength(b));
}

// 判断方向趋同
bool sameDirection(const Vec3 &a, const Vec3 &b) {
    return dot(a, b) > 0;
}

// 投影长度: a在b的投影向量
Vec3 project(const Vec3 &a, const Vec3 &b) {
    return b  * ( a * b / (b * b) );
}

// 向量积 a x b
Vec3 cross(const Vec3 &a, const Vec3 &b) {
    Vec3 result{};
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}

// 标准化
Vec3 normalize(const Vec3 &a) {
    Vec3 result{};
    const float length = getLength(a);
    result.x = a.x / length;
    result.y = a.y / length;
    result.z = a.z / length;
    return result;
}


template<size_t N>
float VecN<N>::getN() {
    return N;
}

template<size_t N>
float VecN<N>::operator[](size_t index) const {
    return data[index];
}

template<size_t N>
VecN<N> VecN<N>::operator+(const VecN &other) const {
    VecN result{};
    for (size_t i = 0; i < N; i++) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

template<size_t N>
VecN<N> VecN<N>::operator-(const VecN &other) const {
    VecN result{};
    for (size_t i = 0; i < N; i++) {
        result.data[i] = data[i] - other.data[i];
    }
    return result;
}

template<size_t N>
VecN<N> VecN<N>::operator*(float scalar) const {
    VecN result{};
    for (size_t i = 0; i < N; i++) {
        result.data[i] = data[i] * scalar;
    }
    return result;
}

template<size_t N>
VecN<N> VecN<N>::operator/(float scalar) const {
    VecN result{};
    for (size_t i = 0; i < N; i++) {
        result.data[i] = data[i] / scalar;
    }
    return result;
}

template<size_t N>
float VecN<N>::operator*(const VecN &other) const {
    float result{0.f};
    for (size_t i = 0; i < N; i++) {
        result += data[i] * other.data[i];
    }
    return result;
}

// 比较器，注意浮点数精度问题
template<size_t N>
bool VecN<N>::operator==(const VecN &other) const {
    for (size_t i = 0; i < N; ++i) {
        if (std::fabs(data[i] - other.data[i]) > 1e-6f) {
            return false;
        }
    }
    return true;
}

template<size_t N>
bool VecN<N>::operator>(float scalar) const {
    for (size_t i = 0; i < N; ++i) {
        if (data[i] <= scalar) return false;
    }
    return true;
}

template<size_t N>
float getLength(const VecN<N> &a) {
    float result{};
    for (size_t i = 0; i < N; i++) {
        result += a.data[i] * a.data[i];
    }
    return std::sqrt(result);
}

template<size_t N>
float dot(const VecN<N> &a, const VecN<N> &b) {
    return a * b;
}

template<size_t N>
float cosAngle(const VecN<N> &a, const VecN<N> &b) {
    const float lenA = getLength(a);
    const float lenB = getLength(b);
    if (lenA == 0 || lenB == 0) return INFINITY;
    return a * b / (lenA * lenB);
}

template<size_t N>
bool sameWay(const VecN<N> &a, const VecN<N> &b) {
    return a * b > 0;
}

// 仅限二维向量比较
template<size_t N>
bool inLeft(const VecN<N> &a, const VecN<N> &b) {
    static_assert(N == 2, "inLeft() is only defined for 2D vectors");
    return a[0] * b[1] - a[1] * b[0] > 0;
}

template<size_t N>
bool inRight(const VecN<N> &a, const VecN<N> &b) {
    static_assert(N == 2, "inRight() is only defined for 2D vectors");
    return a[0] * b[1] - a[1] * b[0] < 0;
}

template<size_t N>
VecN<N> project(const VecN<N> &a, const VecN<N> &b) {
    return b  * ( a * b / (b * b) );
}

template<size_t N>
VecN<N> cross(const VecN<N> &a, const VecN<N> &b) {
    if constexpr (N == 2) {
        // 2D叉乘返回标量（伪标量）
        VecN<N> result{};
        result[0] = a[0] * b[1] - a[1] * b[0];
        return result;
    }
    else if constexpr (N == 3) {
        // 3D标准叉乘
        VecN<3> result;
        result[0] = a[1] * b[2] - a[2] * b[1];
        result[1] = a[2] * b[0] - a[0] * b[2];
        result[2] = a[0] * b[1] - a[1] * b[0];
        return result;
    }
    else {
        // 编译时错误或运行时错误
        static_assert(N == 2 || N == 3,
            "cross() is only defined for 2D and 3D vectors");
    }
    return VecN<1>{};
}

template<size_t N>
VecN<N> normalize(const VecN<N> &a) {
    return a / getLength(a);
}
