#include <iostream>
#include <vector>
#include <iterator>

class solution {
  public:
    std::vector<int> spiralOrder(const std::vector<std::vector<int>> & mat) {
        std::vector<int> result;
        std::pair<int,int> topleft = std::make_pair(0,0), bottomright = std::make_pair(mat.size()-1, mat[0].size()-1);
        while (topleft <= bottomright) {
            auto temp = getNums(mat, topleft, bottomright);
            std::copy(temp.begin(), temp.end(), std::inserter(result, result.end()));
            topleft.first += 1;
            topleft.second += 1;
            bottomright.first -= 1;
            bottomright.second -= 1;
        }
        return result;
    }

  private:
    std::vector<int> getNums(const std::vector<std::vector<int>> & mat, const std::pair<int,int> & topleft, const std::pair<int,int> & bottomright) {
        std::vector<int> result;
        int i = topleft.first, j = topleft.second;
        if (topleft.first != bottomright.first && topleft.second != bottomright.second) {
            for (; j < bottomright.second; j++)
                result.push_back(mat[i][j]);
            if (bottomright != std::make_pair(i,j)) {
                for (; i < bottomright.first; i++)
                    result.push_back(mat[i][j]);
                for (; j > topleft.second; j--)
                    result.push_back(mat[i][j]);
                for (; i > topleft.first; i--)
                    result.push_back(mat[i][j]);
            }
            else
                result.push_back(mat[i][j]);
        }
        else if (topleft.second != bottomright.second) {
            
        }
        return result;
    }
};

int main() {
    // std::vector<std::vector<int>> mat{
    //     {1,2,3,10},
    //     {4,5,6,11},
    //     {7,8,9,12}
    // };

    std::vector<std::vector<int>> mat{
        {1},
        {2},
        {3}
    };

    solution soln;
    auto vec = soln.spiralOrder(mat);
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}
