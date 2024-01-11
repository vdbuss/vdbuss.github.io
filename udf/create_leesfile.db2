create function leesfile (varchar(250))
  returns table (a int, b int)
  external name 'lflib2!leesfile'
  language C
  parameter style SQL
  scratchpad
  disallow parallel
;
