#pragma once
struct vec2 {
    float x, y;

    vec2(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    vec2 operator+(const vec2& other) const {
        return vec2(x + other.x, y + other.y);
    }

    vec2 operator*(float scalar) const {
        return vec2(x * scalar, y * scalar);
    }

    vec2 operator/(float scalar) const {
        return vec2(x / scalar, y / scalar);
    }
float Magnitude() const;
float Direction() const;
};
