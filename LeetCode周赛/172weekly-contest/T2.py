# 竖直打印单词
class Solution:
    def printVertically(self, s: str) -> List[str]:
        strlist = s.split(' ');
        maxlen = 0
        for sr in strlist:
            if maxlen < len(sr):
                maxlen = len(sr)
        newlist = []
        for sr in strlist:
            if len(sr) < maxlen:
                sr = sr + " " * (maxlen - len(sr))
            newlist.append(sr)
        print(newlist)
        ans = []
        ll = len(strlist)
        i = 0
        while i < maxlen:
            st = ""
            for ss in newlist:
                st = st + ss[i]
            st = st.rstrip()
            ans.append(st)
            i+=1
        return ans
        
