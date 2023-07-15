// ma bai GSS1
uses math;
const maxN = 50000;

type node = record
            presum: int64;
            postsum: int64;
            sum: int64;
            maxsum: int64;
            end;

var
    A: array[1..maxN] of longint;
    Tree: array[1..4*maxN] of node;
    n, m: longint;
    res: node;

function hopnhat(L, R: node): node;
var x: node;
begin
   x.sum := L.sum + R.sum;
   x.presum := max(L.presum,L.sum + R.presum);
   x.postsum := max(R.postsum,R.sum + L.postsum);
   x.maxsum := max(L.postsum + R.presum,max(L.maxsum,R.maxsum));
   exit(x);
end;

Procedure Dungcay(K,be,en: longint);
Var L,R,mid : longint;
Begin
  If (be = en) then
    begin
      Tree[K].presum := A[be];
      Tree[K].postsum := A[be];
      Tree[K].sum := A[be];
      Tree[K].maxsum := A[be];
    end
  Else
    begin
      mid := (be+en) div 2;
      L := 2*K;
      R := L +1;
      Dungcay(L,be,mid);
      Dungcay(R,mid+1,en);
      Tree[K] := hopnhat(Tree[L],Tree[R]);
    end;

End;
//-------------------------------
function TruyVan(K,be,en,L,R: longint): node;
Var mid : longint; a,b,ketqua: node;
Begin
  if ((be>en) or (be>R) or (en<L)) then
    begin
     a.presum := -100000;
     a.postsum := -100000;
     a.sum := -100000;
     a.maxsum := -100000;
     exit(a);
    end;

  If (L<=be) and (R>=en) then
    begin
      exit(Tree[K]);
    end
  else
   begin
     mid := (be+en) div 2;
     a := TruyVan(2*K,be,mid,L,R);
     b := TruyVan(2*K+1,mid+1,en,L,R);
     ketqua := hopnhat(a,b);
     exit(ketqua);
   end;
End;

//-------------------------------
procedure Init(n:longint);
var i: longint;
begin
  for i:=1 to 4*n do
    begin
     Tree[i].presum := -100000;
     Tree[i].postsum := -100000;
     Tree[i].sum := -100000;
     Tree[i].maxsum := -100000;
    end;

end;
//-------------------------------
procedure nhap;
var i,x,y: longint;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  readln;

  Init(n);
  DungCay(1,1,n);

  readln(m);
  for i:=1 to m do
   begin
     Readln(x,y);
     res := TruyVan(1,1,n,x,y);
     Writeln(res.maxsum);
    end;
end;
//------------------------------------------
begin
  //assign(input,'diemso.inp'); reset(input);  assign(output,'diemso.out'); rewrite(output);
    nhap;
  //close(input);  close(output);
end.

