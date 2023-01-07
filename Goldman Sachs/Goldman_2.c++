int distance(vector&p1,vector&p2)
{
return (p1[0]-p2[0])(p1[0]-p2[0]) + (p1[1]-p2[1])(p1[1]-p2[1]);

}
bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    
    
    s<int>s;
    s.insert(distance(p1,p2));
    s.insert(distance(p1,p3));
    s.insert(distance(p1,p4));
    s.insert(distance(p2,p3));
    s.insert(distance(p2,p4));
    s.insert(distance(p3,p4));
   
    
    if(!s.count(0) and s.size()==2)return true;
    
    return false;
    
    
}