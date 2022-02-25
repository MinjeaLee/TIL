import random

a_drama = []
a_movie = []
a_ghibli = []
a_disney = []
a_anime = []

b_drama = []
b_movie = []
b_ghibli = []
b_disney = []
b_anime = []

c_drama = []
c_movie = []
c_ghibli = []
c_disney = []
c_anime = []

d_drama = []
d_movie = []
d_ghibli = []
d_disney = []
d_anime = []

e_drama = []
e_movie = []
e_ghibli = []
e_disney = []
e_anime = []

f_drama = []
f_movie = []
f_ghibli = []
f_disney = []
f_anime = []

drama = list(range(1, 55))
movie = list(range(1, 43))
ghibli = list(range(1, 7))
disney = list(range(1, 13))
anime = list(range(1, 7))


for j in range(9): # drama section
    result = random.choice(drama)
    drama.remove(result)
    a_drama.append(result)

    result = random.choice(drama)
    drama.remove(result)
    b_drama.append(result)

    result = random.choice(drama)
    drama.remove(result)
    c_drama.append(result)

    result = random.choice(drama)
    drama.remove(result)
    d_drama.append(result)
    
    result = random.choice(drama)
    drama.remove(result)
    e_drama.append(result)

    result = random.choice(drama)
    drama.remove(result)
    f_drama.append(result)

for i in range(7): # movie section
    result = random.choice(movie)
    movie.remove(result)
    a_movie.append(result)

    result = random.choice(movie)
    movie.remove(result)
    b_movie.append(result)

    result = random.choice(movie)
    movie.remove(result)
    c_movie.append(result)

    result = random.choice(movie)
    movie.remove(result)
    d_movie.append(result)
    
    result = random.choice(movie)
    movie.remove(result)
    e_movie.append(result)

    result = random.choice(movie)
    movie.remove(result)
    f_movie.append(result)

#ghibli section
result = random.choice(ghibli)
ghibli.remove(result)
a_ghibli.append(result)

result = random.choice(ghibli)
ghibli.remove(result)
b_ghibli.append(result)

result = random.choice(ghibli)
ghibli.remove(result)
c_ghibli.append(result)

result = random.choice(ghibli)
ghibli.remove(result)
d_ghibli.append(result)

result = random.choice(ghibli)
ghibli.remove(result)
e_ghibli.append(result)

result = random.choice(ghibli)
ghibli.remove(result)
f_ghibli.append(result)

for i in range(2): # disney section
    result = random.choice(disney)
    disney.remove(result)
    a_disney.append(result)

    result = random.choice(disney)
    disney.remove(result)
    b_disney.append(result)

    result = random.choice(disney)
    disney.remove(result)
    c_disney.append(result)

    result = random.choice(disney)
    disney.remove(result)
    d_disney.append(result)
    
    result = random.choice(disney)
    disney.remove(result)
    e_disney.append(result)

    result = random.choice(disney)
    disney.remove(result)
    f_disney.append(result)


# anime section
result = random.choice(anime)
anime.remove(result)
a_anime.append(result)

result = random.choice(anime)
anime.remove(result)
b_anime.append(result)

result = random.choice(anime)
anime.remove(result)
c_anime.append(result)

result = random.choice(anime)
anime.remove(result)
d_anime.append(result)

result = random.choice(anime)
anime.remove(result)
e_anime.append(result)

result = random.choice(anime)
anime.remove(result)
f_anime.append(result)

print("a_drame = {}", format(a_drama))
print("a_movies = {}", format(a_movie))
print("a_ghibli = {}", format(a_ghibli))
print("a_disney = {}", format(a_disney))
print("a_anime = {}", format(a_anime))
print("------------------")
print("b_drame = {}", format(b_drama))
print("b_movies = {}", format(b_movie))
print("b_ghibli = {}", format(b_ghibli))
print("b_disney = {}", format(b_disney))
print("b_anime = {}", format(b_anime))
print("------------------")
print("c_drame = {}", format(c_drama))
print("c_movies = {}", format(c_movie))
print("c_ghibli = {}", format(c_ghibli))
print("c_disney = {}", format(c_disney))
print("c_anime = {}", format(c_anime))
print("------------------")
print("d_drame = {}", format(d_drama))
print("d_movies = {}", format(d_movie))
print("d_ghibli = {}", format(d_ghibli))
print("d_disney = {}", format(d_disney))
print("d_anime = {}", format(d_anime))
print("------------------")
print("e_drame = {}", format(e_drama))
print("e_movies = {}", format(e_movie))
print("e_ghibli = {}", format(e_ghibli))
print("e_disney = {}", format(e_disney))
print("e_anime = {}", format(e_anime))
print("------------------")
print("f_drame = {}", format(f_drama))
print("f_movies = {}", format(f_movie))
print("f_ghibli = {}", format(f_ghibli))
print("f_disney = {}", format(f_disney))
print("f_anime = {}", format(f_anime))
