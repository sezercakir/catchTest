#include <iostream>


class point3d
{
private:
    int x_;
    int y_;
    int z_;
    double dx_;
    double dy_;
public:
    point3d(int const x = 0,int const y = 0,int const z = 0, double const dx = 0.0, double const dy = 0.0)
            :x_(x),y_(y),z_(z),dx_(dx),dy_(dy){}
    int getx() const { return x_;}
    int gety() const { return y_;}
    int getz() const { return z_;}
    double getdx() const { return dx_;}
    double getdy() const { return dy_;}

    point3d& y(int const y){
        y_ = y;
        return *this;
    }
    point3d& x(int const x){
        x_ = x;
        return *this;
    }
    point3d& z(int const z){
        z_ = z;
        return *this;
    }
    point3d& dx(double const dx){
        dx_ = dx;
        return *this;
    }
    point3d& dy(double const dy){
        dy_ = dy;
        return *this;
    }

    bool operator==(point3d const &in) const{
        return x_ ==in.x_ && y_ ==in.y_ && z_ ==in.z_ && dy_==in.dy_ && dx_==in.dx_;
    }
    bool operator!=(point3d const & pt) const{
        return !(*this == pt);
    }
    bool operator<(point3d const & pt) const{
        return x_ < pt.x_ || y_ < pt.y_ || z_ < pt.z_ || dx_ < pt.dx_  || dy_ < pt.dy_ ;
    }

    friend std::ostream& operator<<(std::ostream& stream, point3d const & pt){
        stream << "(" << pt.x_ << "," << pt.y_ << "," << pt.z_ << "," << pt.dx_ << "," << pt.dy_ << ")";
        return stream;
    }

    void offset(int const offsetx, int const offsety, int const offsetz, double offsetdx, double const offsetdy){
        x_ += offsetx;
        y_ += offsety;
        z_ += offsetz;
        dx_ += offsetdx;
        dy_ += offsetdy;
    }

    static point3d origin() { return point3d{}; }
    ~point3d() = default;
};

