### 2582.递枕头

`n` 个人站成一排，按从 `1` 到 `n` 编号。

最初，排在队首的第一个人拿着一个枕头。每秒钟，拿着枕头的人会将枕头传递给队伍中的下一个人。一旦枕头到达队首或队尾，传递方向就会改变，队伍会继续沿相反方向传递枕头。

- 例如，当枕头到达第 `n` 个人时，TA 会将枕头传递给第 `n - 1` 个人，然后传递给第 `n - 2` 个人，依此类推。

给你两个正整数 `n` 和 `time` ，返回 `time` 秒后拿着枕头的人的编号。

来源：力扣

https://leetcode.cn/problems/pass-the-pillow/



思路：

​		如果时间为`2*(n-1)`，返回到起点位置。定义`ret = time%(2*(n-1))`，如果`ret<n`，说明最后方向是从队头到队尾，此时拿枕头的人的编号为`ret+1`，否则方向为逆向，此时拿枕头的人的编号为`n*2-ret-1`。