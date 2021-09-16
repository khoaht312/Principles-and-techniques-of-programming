"""
code chạy trên colab:
https://colab.research.google.com/drive/10s3MCm1hugo9l460MCfn8jX_-iZE0gSv#scrollTo=esuiAYjOhnGb
"""

n,m,k = map(int,input().split()) 
n_list = list(map(str,(input().split()))) 
m_list = list(map(int,(input().split()))) 
a = [] # lưu vị trí mỗi người
before = [k]*m # giá trị tối đa mỗi chai
c = [] #tìm trạng thái giống nhau
def max_id(array): #trả về vị trí lớn nhất trong mảng có giá trị > 0
  x = 0
  high = array[0]
  for i in range(len(array)):
    if array[i] >= high and array[i] > 0:
      high = array[i]
      x = i
  return x

def min_id(array): #trả về vị trí nhỏ nhất trong mảng có giá trị > 0
  x = 0
  low = array[0]
  for i in range(len(array)):
    if array[i] <= low and array[i] > 0:
      low = array[i]
      x = i
  return x

for i in range(len(before)):
  x = min_id(before)
  y = max_id(before)
  if n_list[i] == 'E':
    before[x] -= 1
    a.append(x)
  else:
    before[y] -= 1
    a.append(y)

for i in before:
  i = 2-i

for i in reversed(range(len(before))):
  for j in range(len(m_list)):
    if (before[i] == m_list[j]):
      c.append(j)
      before[i] = k+1
      m_list[j] = k+2

def Reverse(lst):
    return [ele for ele in reversed(lst)]
d = Reverse(c)

for i in range(len(a)):
  print(d[a[i]]+1,end = " ")

