### 278.第一个错误版本

你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。

假设你有 `n` 个版本 `[1, 2, ..., n]`，你想找出导致之后所有版本出错的第一个错误的版本。

你可以通过调用 `bool isBadVersion(version)` 接口来判断版本号 `version` 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。

来源：力扣

https://leetcode.cn/problems/first-bad-version/



思路：

​	定义变量`left`和`right`，分别初始化为0和`n-1`。当满足`left<=right`时，定义变量`mid=left+(right-left)/2`，如果`isBadVersion(mid)`为真，就将`right`变为`mid-1`，否则，将`left`变为`mid+1`。

​	最后返回`left`即可。		

