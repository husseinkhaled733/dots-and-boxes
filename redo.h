void redo(int*remMoves,int Size,char game[Size][Size],int*turn,int*moves,int*moves1,int*moves2,int*score1,int*score2,int m,int redogame[*remMoves][8],int copygame[*remMoves][7],int*redomoves,int r)
{
    char h1='a',h2='b',v1='c',v2='d',b1='e',b2='f';
    int c;
    if(m==2)
    {
        copygame[*moves][0]=redogame[*redomoves-1][0];
        copygame[*moves][1]=redogame[*redomoves-1][1];
        copygame[*moves][2]=*turn;
        if((redogame[*redomoves-1][0])%2==1 && (redogame[*redomoves-1][1])%2==0)//horizontal
        {
            if(*turn==1)
            {
                game[redogame[*redomoves-1][0]][redogame[*redomoves-1][1]]=h1;
                *moves1+=1;
                *remMoves-=1;
            }
            else
            {
                game[redogame[*redomoves-1][0]][redogame[*redomoves-1][1]]=h2;
                *moves2+=1;
                *remMoves-=1;
            }
        }
        else if((redogame[*redomoves-1][0])%2==0 && (redogame[*redomoves-1][1])%2==1)//vertical
        {
            if(*turn==1)
            {
                game[redogame[*redomoves-1][0]][redogame[*redomoves-1][1]]=v1;
                *moves1+=1;
                *remMoves-=1;
            }
            else
            {
                game[redogame[*redomoves-1][0]][redogame[*redomoves-1][1]]=v2;
                *moves2+=1;
                *remMoves-=1;
            }
        }
        if(redogame[*redomoves-1][3]!=0)
        {
            copygame[*moves][3]=redogame[*redomoves-1][3];
            copygame[*moves][4]=redogame[*redomoves-1][4];
            if(*turn==1)
            {
                game[redogame[*redomoves-1][3]][redogame[*redomoves-1][4]]=b1;
                *score1+=1;
            }
            else
            {
                game[redogame[*redomoves-1][3]][redogame[*redomoves-1][4]]=b2;
                *score2+=1;
            }
        }
        if(redogame[*redomoves-1][5]!=0)
        {
            copygame[*moves][5]=redogame[*redomoves-1][5];
            copygame[*moves][6]=redogame[*redomoves-1][6];
            if(*turn==1)
            {
                game[redogame[*redomoves-1][5]][redogame[*redomoves-1][6]]=b1;
                *score1+=1;
            }
            else
            {
                game[redogame[*redomoves-1][5]][redogame[*redomoves-1][6]]=b2;
                *score2+=1;
            }
        }
        *turn=redogame[*redomoves-1][2];
        *redomoves-=1;
        *moves+=1;
    }
    else
    {
        c=redogame[*redomoves-1][7];
        while(1)
        {
            if(redogame[*redomoves-c][2]==1)
            {
                copygame[*moves+c-1][0]=redogame[*redomoves-c][0];
                copygame[*moves+c-1][1]=redogame[*redomoves-c][1];
                copygame[*moves+c-1][2]=redogame[*redomoves-c][2];
                if((redogame[*redomoves-c][0])%2==1 && (redogame[*redomoves-c][1])%2==0)
                {
                    game[redogame[*redomoves-c][0]][redogame[*redomoves-c][1]]=h1;
                }
                else if((redogame[*redomoves-c][0])%2==0 && (redogame[*redomoves-c][1])%2==1)
                {
                    game[redogame[*redomoves-c][0]][redogame[*redomoves-c][1]]=v1;
                }
                if(redogame[*redomoves-c][3]!=0)
                {
                    copygame[*moves+c-1][3]=redogame[*redomoves-c][3];
                    copygame[*moves+c-1][4]=redogame[*redomoves-c][4];
                    game[redogame[*redomoves-c][3]][redogame[*redomoves-c][4]]=b1;
                    *score1+=1;
                }
                if(redogame[*redomoves-c][5]!=0)
                {
                    copygame[*moves+c-1][5]=redogame[*redomoves-c][5];
                    copygame[*moves+c-1][6]=redogame[*redomoves-c][6];
                    game[redogame[*redomoves-c][5]][redogame[*redomoves-c][6]]=b1;
                    *score1+=1;
                }
                *moves1+=1;
                *remMoves-=1;
                c--;
                *turn=1;
                *moves=*moves+redogame[*redomoves-1][7];
                *redomoves=*redomoves-redogame[*redomoves-1][7];
                break;
            }
            else//for computer
            {
                copygame[*moves+c-1][0]=redogame[*redomoves-c][0];
                copygame[*moves+c-1][1]=redogame[*redomoves-c][1];
                copygame[*moves+c-1][2]=redogame[*redomoves-c][2];
                if((redogame[*redomoves-c][0])%2==1 && (redogame[*redomoves-c][1])%2==0)
                {
                    game[redogame[*redomoves-c][0]][redogame[*redomoves-c][1]]=h2;
                }
                else if((redogame[*redomoves-c][0])%2==0 && (redogame[*redomoves-c][1])%2==1)
                {
                    game[redogame[*redomoves-c][0]][redogame[*redomoves-c][1]]=v2;
                }
                if(redogame[*redomoves-c][3]!=0)
                {
                    copygame[*moves+c-1][3]=redogame[*redomoves-c][3];
                    copygame[*moves+c-1][4]=redogame[*redomoves-c][4];
                    game[redogame[*redomoves-c][3]][redogame[*redomoves-c][4]]=b2;
                    *score2+=1;
                }
                if(redogame[*redomoves-c][5]!=0)
                {
                    copygame[*moves+c-1][5]=redogame[*redomoves-c][5];
                    copygame[*moves+c-1][6]=redogame[*redomoves-c][6];
                    game[redogame[*redomoves-c][5]][redogame[*redomoves-c][6]]=b2;
                    *score2+=1;
                }
                *moves2+=1;
                *remMoves-=1;
                c--;
            }
        }
    }
}

