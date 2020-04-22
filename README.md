# 42-lem_in
In this project we had to solve following problem:
Your ant colony must move from one point to another. How do you do it in the shortest time possible? 
This project got us acquainted with graph traversal algorithms as our program has to intelligently select paths and precise movements used by the ants.

This project was done with my wonderful team mate [Hoang Pham](https://github.com/shilena91).

# Usage
```
git clone https://github.com/avocadohooman/42-lem_in.git | cd 42-lem_in
./lem_in < <test_map>
e.g.:
./lem_in < map_thousand6
```

# Notes by the Creator
Although our algorithm is effiecient and fast enough to pass the reuired criteria posed by the subject, it is not perfect.
We are reading and printing the file line by line, which is not the fastest approach. We could increase the speed by storing first everything 
in a buffer and then flushing it.
Also, our algorithm does not perfectly distribute and ants and use the paths in the most efficient way. However, we feel like we
learnt the essential of graph traversal algorithms and are happy with the resulst. 

