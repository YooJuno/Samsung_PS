
            // for(j = 0; j < N-1; j++)
            // {
            //     if(abs(map[j][i]-map[j+1][i]) > 1)
            //     {
            //         break;
            //     }
            //     // 오르막길
            //     else if(map[j][i]-map[j+1][i] == -1)
            //     {
            //         if(j-X+1 < 0) break;
            //         bool isPossible = true;
            //         for(auto k = j-X+1; k < j+1; k++)
            //         {
            //             if(map[k][i] != map[k+1][i]) 
            //             {
            //                 isPossible = false;
            //                 break;
            //             }
            //         }
            //         if(!isPossible) break;
            //     }
            //     // 내리막길
            //     else if(map[j][i]-map[j+1][i] == 1)
            //     {
            //         if(j+X+1 >= N ) break;
            //         bool isPossible = true;
            //         for(auto k = j+1; k <= j+X; k++)
            //         {
            //             if(map[k][i] != map[k+1][i]) 
            //             {
            //                 isPossible = false;
            //                 break;
            //             }
            //         }
            //         if(!isPossible) break;
            //     }
            // }
            // if(j == N-1) 
            // {
            //     result++;
            //     cout << "2 => " << i;
            //     cout << endl;
            // }