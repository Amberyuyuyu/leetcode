### 1333.餐厅过滤器

给你一个餐馆信息数组 `restaurants`，其中 `restaurants[i] = [idi, ratingi, veganFriendlyi, pricei, distancei]`。你必须使用以下三个过滤器来过滤这些餐馆信息。

其中素食者友好过滤器 `veganFriendly` 的值可以为 `true` 或者 `false`，如果为 *true* 就意味着你应该只包括 `veganFriendlyi` 为 true 的餐馆，为 *false* 则意味着可以包括任何餐馆。此外，我们还有最大价格 `maxPrice` 和最大距离 `maxDistance` 两个过滤器，它们分别考虑餐厅的价格因素和距离因素的最大值。

过滤后返回餐馆的 ***id\***，按照 ***rating*** 从高到低排序。如果 ***rating*** 相同，那么按 ***id*** 从高到低排序。简单起见， `veganFriendlyi` 和 `veganFriendly` 为 *true* 时取值为 *1*，为 *false* 时，取值为 *0 。*

来源：力扣

https://leetcode.cn/problems/filter-restaurants-by-vegan-friendly-price-and-distance/



思路：

​		按照题目要求，来完成代码即可。

​		定义二级指针`filtered`，用于存放符合条件的餐厅信息。定义`filteredSize`，初始化为0，表示符合条件的餐厅个数。	遍历真整个`restaurants`，在满足`restaurants[i][3]<=maxPrice&&restaurants[i][4]<=maxDistance`的条件下，如果满足`veganFriendly&&restaurants[i][2]`，就将`restaurants[i]`加入`filtered`数组中。如果`veganFriendly`为假，也将`restaurants[i]`加入`filtered`数组中。

​		定义`cmp`函数，借助快排对`filtered`数组进行排序。

​		定义`ret`数组，长度为`filteredSize`，按照顺序将`filtered[i][0]`加入`ret`数组，返回`ret`数组即可。