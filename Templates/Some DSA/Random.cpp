std::mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
ll rand(ll l,ll r)
{
    return uniform_int_distribution<ll>(l, r)(rng);
}
