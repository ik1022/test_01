#pragma once

class ClassValue
{
    int value, min, max;

  public:
    ClassValue(int init, int min = 1, int max = 1000) : value(init), min(min), max(max) {};
    ~ClassValue() {};

    inline void setValue(int v) { value = v < min ? min : v > max ? max : v; };

    inline int getValue() { return value; };

    inline void setScale(int in_min, int in_max, int v) { value = map(v, in_min, in_max, min, max); }

    inline int getScale(int in_min, int in_max) { return map(value, min, max, in_min, in_max); }

    int map(int x, int in_min, int in_max, int out_min, int out_max)
    {
        if (in_min < in_max)
        {
            if (x < in_min) return in_min;
            if (x > in_max) return in_max;
        }
        else if (in_min > in_max)
        {
            if (x > in_min) return in_min;
            if (x < in_max) return in_max;
        }
        return (int)((((x - in_min) * (out_max - out_min)) / (in_max - in_min)) + out_min);
    };
};
