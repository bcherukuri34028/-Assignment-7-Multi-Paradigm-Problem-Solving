let mean lst =
  let sum = List.fold_left ( +. ) 0.0 (List.map float_of_int lst) in
  sum /. float_of_int (List.length lst)

let median lst =
  let sorted = List.sort compare lst in
  let len = List.length sorted in
  if len mod 2 = 1 then
    float_of_int (List.nth sorted (len / 2))
  else
    let mid1 = List.nth sorted ((len / 2) - 1) in
    let mid2 = List.nth sorted (len / 2) in
    (float_of_int (mid1 + mid2)) /. 2.0

let mode lst =
  let counts =
    List.fold_left (fun acc x ->
      let count = try List.assoc x acc with Not_found -> 0 in
      (x, count + 1) :: List.remove_assoc x acc
    ) [] lst in
  let max_freq = List.fold_left (fun acc (_, count) -> max acc count) 0 counts in
  List.fold_left (fun acc (num, count) ->
    if count = max_freq then num :: acc else acc
  ) [] counts

let () =
  let numbers = [1; 2; 2; 3; 4; 4; 4; 5] in
  Printf.printf "Mean: %.2f\n" (mean numbers);
  Printf.printf "Median: %.2f\n" (median numbers);
  Printf.printf "Mode: ";
  List.iter (Printf.printf "%d ") (List.rev (mode numbers));
  Printf.printf "\n"
