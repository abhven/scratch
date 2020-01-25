/**
 * @brief You are given a 2D world with each cell containig the state of the cell. 
 *        At every time step a cell is brought back to life, killed or maintains 
 *        state based on certain conditions based on its neighbours
 */

#include<cassert>
#include<vector>
#include<iostream>

using namespace std;
class World {
  private:
    vector<vector<int>> world2D;
    size_t rows;
    size_t cols;
  public:
    World(vector<vector<int>>& W) : world2D{W} {
        rows = W.size();
        cols = W[0].size();
    };
    void print(); /* prints the current state of the world */
    void step_time(); /* steps the world by one time step */
};

void World::print() {
    for (auto i = world2D.begin(); i!= world2D.end(); i++) {
        for(auto j = i->begin() ;  j!= i->end(); j++)
            cout<< *j <<" ";
        cout<<"\n";
    }
    cout<<'\n';
}

void World::step_time(){
    vector<vector<int>> update (rows, vector<int> (cols, 0));
    vector<vector<int>> delta = {{1,0}, {-1, 0}, {0,1}, {0, -1}};
    for (int i = 0 ; i< rows; i++)
        for(int j =0; j< cols; j++) {
            int alive = 0;
            for(auto k = delta.begin() ; k != delta.end(); k++)
            {
                int x = i + (*k)[0];
                int y = j + (*k)[1];
                if(x >= 0 && x< rows && y >= 0 && y< cols)
                {
                    if(world2D[x][y])
                        alive++;
                }
            }
            switch(alive) {
                case 0: break;
                case 1: if(!world2D[i][j])
                            update[i][j] = 1;
                        break;
                case 2: if(world2D[i][j])
                            update[i][j] = 0;
                        else
                            update[i][j] = 1;
                        break;
                case 3: if(world2D[i][j])
                            update[i][j] = 0;
                default: break;
            }
        }
        world2D = update;

}
int main() {
    vector<vector<int>> v{{1, 0, 1}, {0, 0, 0}, {1, 1, 0}};
    World world(v);
    world.print();
    for(int i =0 ; i< 10; i++) {
        world.step_time();
        world.print();
    }
}