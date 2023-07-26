const
        fo='nopot04.inp';
        maxn=10; maxm=20;        maxq=5;   maxw=10;
var   t,n,m,q,s,k: longint;

procedure taotest;
var x,i,j,u,v,w,wmax:longint;
begin
        randomize;
        t := random(2)+2;
        //t := 1;
        writeln(t);
  for x:=1 to t  do
    begin
        n := random(maxn)+3;
        m := 2*n-3;;
        q := random(maxq)+1;
        writeln(n,#32,m,#32,q);
        wmax := 0;
        for i:=1 to (n-2) do
          begin
             u := i+1;
             v := i+2;
             w := random(maxw)+1;
             writeln(i,#32,u,#32,w);
             if w>wmax then wmax := w;
             w := random(maxw)+1;
             writeln(i,#32,v,#32,w);
             if w>wmax then wmax := w;
          end;
       w := random(maxw)+1;
       writeln(u,#32,v,#32,w);
       if w>wmax then wmax := w;
       for j:=1 to q do
         begin
            k:= random(m)+1; s := m;
            write(k,#32,s,#32);
            for i:=1 to s do  write(i,#32,wmax+random(5)+1,#32);
            writeln;
         end;
   end;
end;

begin
        assign(output,fo);rewrite(output);
        taotest;
        close(output);
end.
