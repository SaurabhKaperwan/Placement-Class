// Divide input stream in half and first half is maxHeap and second half is minHeap
//If n is odd then median is maxHeap.top()
//If n is even then median is (maxHeap.top()+minHeap.top())/2.0
class MedianFinder 
{
    public:

        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        MedianFinder() 
        {
        
        }
    
        void addNum(int num) 
        {
            int l = maxHeap.size();
            int r = minHeap.size();

            if(l == 0)
                maxHeap.push(num);
            else if(l == r)
            {
                if(num < minHeap.top())
                    maxHeap.push(num);
                else
                {
                    int temp = minHeap.top();
                    minHeap.pop();
                    minHeap.push(num);
                    maxHeap.push(temp);
                }
            }
            else
            {
                if(num < maxHeap.top())
                {
                    int temp = maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(num);
                    minHeap.push(temp);
                }
                else
                    minHeap.push(num);
            }
        }
    
        double findMedian() 
        {
            int l = maxHeap.size();
            int r = minHeap.size();

            if(l > r)
                return maxHeap.top();
            else
                return (maxHeap.top()+minHeap.top())/2.0;

        }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
