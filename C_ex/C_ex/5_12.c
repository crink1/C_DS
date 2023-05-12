int search(int* nums, int numsSize, int target){

    //不用看就知道二分法

    //观察后，易知，先和nums[0]比较，若比其大，则在前半部分找，若比起小，则只能在后半部分找【原升序的特性】

    if(numsSize==1){

        if(nums[0]==target)

            return 0;

        return -1;

    }

    int first=0,last = numsSize-1;

    if(nums[0]>target){//后部分找 前部分都比target大 二分下去比nums[last]大，则为前部分的，还需后移动，否则为后部分的 正常二分

        while(first<last){

            if(nums[(first+last)/2]>nums[last]){

                first=(first+last)/2+1;

            }else{//定位到后部分了

                if(nums[(first+last)/2]>target){//定位过了

                    last=(first+last)/2-1;

                }

                else{//定位正确

                    first=(first+last)/2;

                    if(nums[(first+last)/2]==target)

                        return (first+last)/2;

                    while(first<last){//正常二分

                        if(nums[(first+last)/2]>=target)

                            last=(first+last)/2;

                        else   

                            first = (first+last)/2+1;

                    }

                    if(nums[first]!=target)

                        return -1;

                    return first;

                }

            }

        }

        

    }else{//前部分找【后部分都比target小】first先不动，last二分定位到比target大的 再二分

        while(first<last){

            if(nums[(first+last)/2]<nums[first]){

                last=(first+last)/2-1;

            }else{//定位到前部分了

                if(nums[(first+last)/2]<target){//定位过了

                    first=(first+last)/2+1;

                }

                else{//定位正确a

                    last=(first+last)/2;

                    if(nums[(first+last)/2]==target)

                        return (first+last)/2;

                    while(first<last){//正常二分

                        if(nums[(first+last)/2]>=target)

                            last=(first+last)/2;

                        else   

                            first = (first+last)/2+1;

                    }

                    if(nums[first]!=target)

                        return -1;

                    return first;

                }

            }

        }

    }

    if (nums[first] != target)

        return -1;

    return first;

}
