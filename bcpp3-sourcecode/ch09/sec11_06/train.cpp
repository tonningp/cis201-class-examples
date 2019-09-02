class Train
{
public:
   void move(double distance_moved);
   double get_position();
   
private:
   double distance_from_terminus;
};
   
void Train::move(double distance_moved)
{
   distance_from_terminus = distance_from_terminus + distance_moved;
}

double Train::get_position()
{
   return distance_from_terminus;
}
