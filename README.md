<h1> <strong><u>DS Project Documentation</u></strong> </h1> 

<h2> BST &amp; AVL tree Implementations</h2> 

&nbsp;
&nbsp;

<strong>Supervisor</strong><strong>: </strong><strong><em>Dr Shimaa Ibrahim. </em></strong>

<strong>Supervisor assistant</strong><strong>: </strong><strong><em>Eng Mohamed Hassan. </em></strong>

<strong>Student</strong><strong>:</strong><strong> <em>Mahmoud Sayed Abd El-Magied.</em></strong>

&nbsp;
<h2><em><u>Project description</u></em>: </h2> 

The project contains two types of binary tree data structure implementations: - generic implementations -
<ul>
	<li>Binary Search Tree (BST)</li>
	<li>AVL tree</li>
</ul>
The implemented trees in this project hold always data as a combination of key and value.

The project enables users to do several operations
<ul>
	<li>Insert data: inserting new key and its value.</li>
	<li>Modify data: modifying value of specific key</li>
	<li>Insert or modify: insert key and its value if the key doesn’t exist, otherwise modifying the key’s value with the new value.</li>
	<li>Contains key: determine if the key exists or not.</li>
	<li>Get value: get the value if specific key.</li>
	<li>Print: print the data in non-decreasing order according to its keys.</li>
</ul>
&nbsp;

<h2><em><u>Project components and tools</u></em>: </h2> 

I used <a href="https://eclipse.org/cdt/">Eclipse CDT</a> to implement this project and used <a href="https://git-scm.com/">git</a> as a version control system.

The project contains:
<ul>
	<li>Map header: contains the tree’s attributes and functions definitions.</li>
	<li>DS namespace: contains the tree class and its implementation.</li>
	<li>Map class: contains the tree attributes and functions implementations.</li>
</ul>
You can find the project here: <a href="https://github.com/M-Sayed/BST-generic-implementation.-">BST generic implementation</a>

&nbsp;
<h2> <em><u>Project classes</u></em>: </h2> 

<ul>
	<li>BST class</li>
</ul>
<table>
<tbody>
<tr>
<td colspan="2" width="582"><center> map </center> </td>
</tr>
<tr>
<td width="384">
+ map() <br>

+ map(T1, T2) <br>

+ ~map()<br>

+ containsKey(T1)<br>

+ getValue()<br>

+ insert(T1, T2)<br>

+ modify(T1, T2)<br>

+ insertOrModify(T1, T2)<br>

+ print()<br>

&nbsp;</td>
<td width="198">default constructor<br>

constructor<br>

destructor<br>

bool<br>

T1<br>

void<br>

void<br>

void<br>

void<br></td>
</tr>
<tr>
<td width="384">
- _search(node*, T1)<br>

- _insert(node*, node*, T1, T2)<br>
- _modify(node*, T1, T2)<br>

- _print(node*)<br>

- _destroy(node*)<br>

&nbsp;</td>
<td width="198">node*<br>

void<br>

void<br>

void<br>

void<br></td>
</tr>
</tbody>
</table>


<ul>
	<li>AVL class</li>
</ul>
<table>
<tbody>
<tr>
<td colspan="2" width="582"><center>map </center> </td>
</tr>
<tr>
<td width="384"> 
+ map() <br>

+ map(T1, T2) <br>

+ ~map()<br>

+ containsKey(T1)<br>

+ getValue()<br>

+ insertAVL(T1, T2)<br>

+ modify(T1, T2)<br>

+ insertOrModifyAVL(T1, T2)<br>

+ print()<br>

&nbsp;</td>
<td width="198">default constructor<br>

constructor<br>

destructor<br>

bool<br>

T1<br>

void<br>

void<br>

void<br>

void<br></td>
</tr>
<tr>
<td width="384">- _search(node*, T1)<br>

- _insertAVL(node*, node*, T1, T2)<br>

- _modify(node*, T1, T2)<br>

- _print(node*)<br>

- singleRotateLeft(node*)<br>

- singleRotateRight(node*)<br>

- doubleRotateLeft(node*)<br>

- doubleRotateRight(node*)<br>

- _destroy(node*)<br>

&nbsp;</td>
<td width="198">node*<br>

void<br>

void<br>

void<br>

void<br></td>
</tr>
</tbody>
</table>
