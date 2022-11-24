import Prob1 as p1


def test_1():
    manans = "fight with Fist Hit Power is 3.0 "
    swordmanans = "fight with Sword Hit Power is 213 "
    p1ans = p1.Problem1()
    assert p1ans[0] == manans and p1ans[1] == swordmanans