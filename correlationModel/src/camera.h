#ifndef CAMERA_H
#define CAMERA_H

typedef struct Position{
  Position(){}
  Position(double X, double Y):x(X),y(Y){}
  double x; // x position(m)
  double y; // y position(m)
} Position;

class Camera {
  public:
    Camera(double D, double Theta, double F, double R):d(D),theta(Theta),f(F),
    r(R){}

    double get_d(){ return d;}
    double get_theta(){ return theta;}
    double get_f(){ return f;}
    double get_r(){ return r;}

    void set_d( double D ){ d = D;}
    void set_theta( double Theta ){ theta = Theta; }
    void set_f( double F ){ f = F; }
    void set_r( double R ){ r = R; }

  private:
    static double oiginPoint; 
    double d;      //distance to the origin point (m)
    double theta;  //argument angle
    double f;      //focal length (m)
    double r;      //distance shift of given d and theta.
};

class CameraPos {
  public:
    CameraPos( Position Pos, double Dir, double F):pos(Pos),dir(Dir),f(F){}

    // Basic query
    Position get_position(){return pos;}
    double get_direction(){return dir;}
    double get_f(){ return f;}

    Position set_position ( Position Pos){ pos = Pos; }
    double   set_direction( double Dir){ dir = Dir;}
    void set_f( double F ){ f = F; }
   
    // Advance operation
    double corrCoeff( CameraPos neighbor, Position area);

  private:
    static double oiginPoint; 
    Position pos;           // position
    double dir;             // direction (arc)
    double f;               // focal length (m)
    double FoV;             // (arc)
    double sensingRadius;   // (m)
};
#endif
