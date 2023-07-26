const maxN = 1000000;

var
    T: array[-1..maxN] of longint;
    s,w: ansistring;
    n,m,ans: longint;
    s1:string;

procedure nhap;
begin
  s:='';
  while not eof()  do
     begin
         readln(s1);
         s:=s+s1;
     end;
  w:=s1; //xau b
  m := length(w);
  s:=copy(s,1,length(s)-m); //xau a
  n := length(s);
end;


procedure kmp;
var k,i,j: longint;
begin
    // lap bang so khop mot phan
    T[1] := 0;
    k := 0;
    for i:=2 to m do
     begin
        while (k>0) and (w[k+1] <> w[i]) do k := T[k];
        if (w[k+1] = w[i]) then inc(k);
        T[i] := k;
     end;

	// so khop
    j := 1;  // vi tri bat dau so khop trong S
    k := 0;  // vi tri so khop trong w
    while (j+m-1) <= n do  // trong khi pham vi so khop con thuoc S
      begin
         while (k<m) and (w[k+1] = s[j+k]) do inc(k);
         if k=m then write(j,#32);
         if k = 0 then inc(j) else begin j := j+k-T[k]; k := T[k]; end;
      end;

end;
//------------------------------------------
begin
  assign(input,'xaucon.inp'); reset(input);  assign(output,'xaucon.out'); rewrite(output);
    nhap;
    kmp;
   close(input);  close(output);
end.

