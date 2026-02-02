multiset<int> L , R;
    

    void add(int val , int k, long long &currentSum){

        L.insert(val);
        currentSum +=val;

        if(L.size() > k-1){
            int largest_l = *L.rbegin();
            L.erase(prev(L.end()));

            currentSum -=largest_l;
            R.insert(largest_l);
        }

        // if largest in l is greater than smaller in R
        if(!L.empty() && !R.empty() && *L.rbegin() > *R.begin()){
            int largest_l = *L.rbegin();
            int smallest_r = *R.begin();

            L.erase(prev(L.end()));
            currentSum -=largest_l;
            R.erase(R.begin());

            R.insert(largest_l);
            L.insert(smallest_r);
            currentSum +=smallest_r;
        }

    }
    void remove(int val, int k , long long &currentSum){

        auto it = R.find(val);
        if( it!=R.end() ){
            R.erase(it);
        }

        else{
            auto it_l = L.find(val);
            if (it_l != L.end()) {
                L.erase(it_l);
                currentSum -= val;
            }
            if (L.size() < k-1 && !R.empty()) {
                int smallest_R = *R.begin();
                R.erase(R.begin());
                L.insert(smallest_R);
                currentSum += smallest_R;
            }
        }
    }
