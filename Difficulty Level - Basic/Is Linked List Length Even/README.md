<h2><a href="https://www.geeksforgeeks.org/problems/linked-list-length-even-or-odd/1">Is Linked List Length Even?</a></h2><h3>Difficulty Level : Difficulty: Basic</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">Given a linked list, your task is to complete the&nbsp;function <strong>isLengthEven() </strong>which contains the <strong>head</strong> of the linked list, and check whether the length of the linked list is even or not. Return true if it is even, otherwise false.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">Input: </strong><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">Linked list: 12-&gt;52-&gt;10-&gt;47-&gt;95-&gt;0<br><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700573/Web/Other/blobid1_1720646145.png" width="400" height="80"><br></span><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;"><strong>Output: </strong>true</span><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;"><br></span><strong style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">Explanation: </strong><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">The length of the linked list is 6 which is even, hence returned true.</span></span></pre>
<pre><span style="font-size: 14pt;"><strong style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">Input: </strong><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">Linked list: 9-&gt;4-&gt;3<br><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700573/Web/Other/blobid0_1720646126.png" width="400" height="80"><br></span><strong style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">Output: </strong><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">false<br></span><strong style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">Explanation: </strong><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">The length of the linked list is 3 which is odd, hence returned false.</span></span></pre>
<p><span style="font-size: 14pt;"><span style="font-family: arial, helvetica, sans-serif;"><span style="box-sizing: border-box; font-weight: bolder; line-height: 1.7em; color: #1e2229; background-color: #ffffff;">Expected Time Complexity:</span><span style="color: #1e2229; background-color: #ffffff;"> O(n)<br></span></span><span style="font-family: arial, helvetica, sans-serif;"><span style="box-sizing: border-box; font-weight: bolder; line-height: 1.7em; color: #1e2229; background-color: #ffffff;">Expected Auxillary Space</span></span><span style="font-family: arial, helvetica, sans-serif; box-sizing: border-box; font-weight: bolder; line-height: 1.7em; color: #1e2229; background-color: #ffffff;">:</span><span style="font-family: arial, helvetica, sans-serif; color: #1e2229; background-color: #ffffff;"> O(1)<br><br></span></span><strong style="font-size: 14pt; font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">Constraints:<br></strong><span style="font-size: 14pt; font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">1 &lt;= number of nodes &lt;= 10<sup>5</sup></span><sup style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;"><br></sup><span style="font-size: 14pt; font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">1 &lt;= elements of the linked list &lt;= 10</span><sup>5</sup></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Linked List</code>&nbsp;<code>Data Structures</code>&nbsp;