#include <iostream>
#include <vector>
#include <unistd.h>
#include <stdexcept>

class Game
{
private:
    int rows, cols, startingPoints;
    std::vector<std::vector<int>> grid;
    std::vector<std::vector<int>> previousGrid;

    void initializeGrid()
    {
        grid = std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0));
        srand(time(0));
        for (int i = 0; i < startingPoints; ++i)
        {
            int x = rand() % rows;
            int y = rand() % cols;
            grid[x][y] = 1;
        }
    }

    void printGrid(const std::vector<std::vector<int>> &grid)
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] == 1)
                {
                    std::cout << "O";
                }
                else
                {
                    std::cout << ".";
                }
            }
            std::cout << std::endl;
        }
    }

    int countNeighbors(const std::vector<std::vector<int>> &grid, int x, int y)
    {
        int count = 0;
        for (int i = -1; i <= 1; ++i)
        {
            for (int j = -1; j <= 1; ++j)
            {
                if (i == 0 && j == 0)
                    continue;
                int ni = x + i;
                int nj = y + j;
                if (ni >= 0 && ni < rows && nj >= 0 && nj < cols)
                {
                    count += grid[ni][nj];
                }
            }
        }
        return count;
    }

    void updateGrid(std::vector<std::vector<int>> &grid)
    {
        std::vector<std::vector<int>> newGrid = grid;

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                int liveNeighbors = countNeighbors(grid, i, j);

                if (grid[i][j] == 1)
                {

                    if (liveNeighbors < 2 || liveNeighbors > 3)
                    {
                        newGrid[i][j] = 0;
                    }
                }
                else
                {

                    if (liveNeighbors == 3)
                    {
                        newGrid[i][j] = 1;
                    }
                }
            }
        }

        grid = newGrid;
    }

public:
    Game(int rows, int cols, int startingPoints)
    {
        this->rows = (rows > 0) ? rows : 20;
        this->cols = (cols > 0) ? cols : 40;
        this->startingPoints = (startingPoints > 0) ? startingPoints : 50;
        initializeGrid();
    }

    void start()
    {
        while (true)
        {
            previousGrid = grid;
            printGrid(grid);
            updateGrid(grid);
            if (grid == previousGrid)
                break;
            usleep(1000000);
            system("cls");
        }
    }

    void end()
    {
        printf("Game finished\n");
    }
};

int main()
{
    int *cols = new int;
    int *rows = new int;
    int *startingPoits = new int;

    printf("How many rows: ");
    std::cin >> *rows;
    printf("How many columns: ");
    std::cin >> *cols;
    printf("How many starting points: ");
    std::cin >> *startingPoits;


    system("clear");
    Game game(*rows, *cols, *startingPoits);
    delete cols, rows, startingPoits;
    game.start();
    game.end();

    system("pause");
    return 0;
}
