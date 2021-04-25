class Color
{
private:
    float r;
    float g;
    float b;

public:
    Color()
    {
        r = 1.0;
        g = 1.0;
        b = 1.0;
    }
    void setColor(float r, float g, float b)
    {
        this->r = r;
        this->g = g;
        this->b = b;
    }
    float getR()
    {
        return this->r;
    }
    float getG()
    {
        return this->g;
    }
    float getB()
    {
        return this->b;
    }
};