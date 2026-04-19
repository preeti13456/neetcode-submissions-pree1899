class Twitter {
    Map<Integer, ArrayList<int[]>> tweetMap;
    Map<Integer, HashSet<Integer>> followMap;
    int time;

    public Twitter() {
        tweetMap = new HashMap<>();
        followMap = new HashMap<>();
        time = 0;
    }

    public void postTweet(int userId, int tweetId) {
        tweetMap.computeIfAbsent(userId, k -> new ArrayList<>()).add(new int[]{tweetId, time++});
    }

    public List<Integer> getNewsFeed(int userId) {
        List<Integer> res = new ArrayList<>();
        // Tweets IDs should be ordered from most recent to least recent.
        // Using maxHeap (priority queue)
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>((a, b) -> b[1] - a[1]);
        this.follow(userId, userId); // User follows themselves

        Set<Integer> followees = followMap.get(userId);
        for (int followeeId : followees) {
            List<int[]> tweets = tweetMap.get(followeeId);
            if (tweets != null && tweets.size() > 0) {
                int[] recentTweet = tweets.get(tweets.size() - 1);
                maxHeap.add(new int[]{recentTweet[0], recentTweet[1], followeeId, tweets.size() - 1});
            }
        }
        while (!maxHeap.isEmpty() && res.size() < 10) {
            int[] recentTweet = maxHeap.poll();
            res.add(recentTweet[0]);
            int followeeId = recentTweet[2];
            int nextIdx = recentTweet[3] - 1;
            if (nextIdx >= 0) {
                int[] nextTweet = tweetMap.get(followeeId).get(nextIdx);
                maxHeap.add(new int[]{nextTweet[0], nextTweet[1], followeeId, nextIdx});
            }
        }
        return res;
    }

    public void follow(int followerId, int followeeId) {
        followMap.computeIfAbsent(followerId, k -> new HashSet<>()).add(followeeId);
    }

    public void unfollow(int followerId, int followeeId) {
        Set<Integer> followees = followMap.get(followerId);
        if (followees != null && followerId != followeeId) followees.remove(followeeId);
    }
}