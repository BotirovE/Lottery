#ifndef HASHTABLE_H
#define HASHTABLE_H
class Hashtable{
private:
	Player table[59];//if players amount was 15 000 000 then hashtable size would be 15 487 867, or other
	//find fully coincidence
	void find6(int combination[6])
	{
		int index;
		bool thereis = false;
		//In what index this combination is?
		index = compression(hashing(combination));
		//Is this index is empty if YES No winner
		if (table[index].name == "empty")
			cout << "There is noone who guessed 6 numbers" << endl;
		else//If not empty then there maybe winner
		{
			//check linked list in that index
			Player* temp;
			temp = &table[index];
			while (temp != NULL)
			{
				if (hashing(temp->combination) == hashing(combination))
				{
					//if node's combination is same as winning combination that he wins
					cout << temp->name << " was able to find winning combination!" << endl;
					thereis = true;//we have winner
				}
				temp = temp->next;
			}
			if (!thereis)//Whether there is winner or not
				cout << "There is noone who guessed 6 numbers" << endl;
		}

	}
	// Is anyone guessed 5 numbers correctly?
	void find5(int combination[6]){
		int n_combination[6];//combination that partly winner may have
		bool partly = false;
		for (int i = 0; i < 50;i++)
		{
			bool isequal = false;
			for (int j = 0; j < 6; j++)
			{
				if (i == combination[j])
					isequal = true;// check all combinations but avoid having two same numbers
			}
				if (!isequal)
				{
					//change winning combination and find likewise(with 5 numbers) combination
					for (int k = 0; k < 6; k++)
					{
						for (int l = 0; l < 6;l++)
							n_combination[l] = combination[l];

						n_combination[k] = i;
						int index;
						index = compression(hashing(n_combination));
						//
						if (table[index].name != "empty")
						{
							//cout << "Is not empty!" << endl;
							Player* temp;
							temp = &table[index];
							while (temp != NULL)
							{
								if (hashing(temp->combination) == hashing(n_combination))
								{
									//cout << "hashing is equal!!" << endl;
									cout << temp->name << " was able to find 5 numbers!" << endl;
									partly = true;
								}
								temp = temp->next;
							}
						}
					}
				}
		}
		if (!partly)
			cout << "There is noone who guessed 5 numbers" << endl;
	}
	// Is anyone guessed 4 numbers correctly?
	void find4(int combination[6]){
	    bool partly=false;
        int combination5[6];
        int combination4[6];
        for(int i=0;i<50;i++)//replace one element
        {
            bool exists = false;//to avoid adding same number as array's native elements
            for(int x=0;x<6;x++)
            {
                if(i==combination[x])
                    exists =true;
            }
            if(!exists)//if this numbers is not exists in the array replace one element of array with this number
            {
                for(int j=0;j<6;j++)//replace it with every element one by one
                {
                    for(int x=0;x<6;x++)//initialize changing array with given array
                        combination5[x] = combination[x];
                    combination5[j]=i;//change j's element
                    for(int k=0;k<50;k++)//replace another element
                    {
                        if(k==combination[j])//check whether it is equal to previously changed element
                            exists = true;
                        for(int x=0;x<6;x++)//check if it exists in changed array
                        {
                            if(k==combination5[x])
                                exists = true;
                        }
                        if(!exists)
                        {
                            for(int m=0;m<6 && m!=j;m++)//replace not replaced element
                            {
                                for(int x=0;x<6;x++)
                                    combination4[x] = combination5[x];
                                combination4[m] = k;//change m's element
                                int index;
                                index = compression(hashing(combination4));
                                //
                                if (table[index].name != "empty")
                                {
                                    //cout << "Is not empty!" << endl;
                                    Player* temp;
                                    temp = &table[index];
                                    while (temp != NULL)
                                    {
                                        if (hashing(temp->combination) == hashing(combination4))
                                        {
                                            //cout << "hashing is equal!!" << endl;
                                            cout << temp->name << " was able to find 4 numbers!" << endl;
                                            partly = true;
                                        }
                                        temp = temp->next;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(!partly)
            cout << "There is noone who guessed 4 numbers" << endl;
	}

public:
	Hashtable(Player all[30])//takes list of players
	{
		for (int i = 0; i < 30; i++)
		{
			put(all[i]);//puts all of them into hashtable
		}
	}
	long long int hashing(int combination[6])
	{
		long long int key=1;
		for (int i = 0; i < 6; i++){
		//	cout << prime[combination[i]] << " ";
			key *= prime[combination[i]];
		}
	//	cout << "key - " << key << endl;

		return key;
	}
	int compression(long long int key)
	{
		//MAD
		int index;
		index = (41 * key + 491) % 37;
		return index;
	}
	void put(Player any)
	{
		int index;
		index = compression(hashing(any.combination));

		if (table[index].name == "empty")
		{
			table[index] = any;
		}
		else
		{
			Player* temp = new Player;
			temp->name = any.name;
			for (int i = 0; i < 6;i++)
				temp->combination[i] = any.combination[i];
			Player* temp1;
			temp1 = &table[index];
			while (temp1->next != NULL)
			{
				temp1 = temp1->next;
			}
			//cout << "Is it working?" << endl;
			temp1->next = temp;
		}
	}
	void findwinners(int combination[6])
	{
		find6(combination);
		find5(combination);
		find4(combination);
	}
};
#endif
