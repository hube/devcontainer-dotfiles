# Identity for repositories owned by the hube-ai GitHub account.
#
# Selected by ~/.gitconfig's includeIf on the remote URL, so a clone is
# attributed correctly the moment it exists and no per-clone setup can be
# forgotten.
#
# THE SCOPE IS THE REPOSITORY, NOT THE REMOTE. One matching remote is enough,
# and everything below then governs every operation in that repository —
# including operations against its other remotes. Git offers no per-remote
# identity or per-remote sshCommand hook, so repository scope is the only scope
# available. The consequence to avoid: a clone holding both a hube and a
# hube-ai remote commits and pushes as hube-ai against both. Keep one account's
# remotes to a clone.
#
# Agents are the primary author in these repositories rather than co-authors,
# so hube-ai owns the author and the committer field alike. GitHub resolves a
# signature against the committer, so the signing key must be hube-ai's: signing
# a hube-ai-committed commit with another account's key yields an unverified
# commit that git reports locally as a good signature.
[user]
        name = hube-ai
        email = 293958300+hube-ai@users.noreply.github.com
        signingKey = ~/.ssh/id_ed25519_hube_ai.pub

# Both keys live in one forwarded agent and GitHub accepts either for these
# repositories, so an unpinned push succeeds while authenticating as the wrong
# account. IdentitiesOnly is what makes the pin hold — and it is also what
# removes any fall-through, so in a repository this include governs there is no
# second key to try. That is why the pin is not set globally: elsewhere the
# agent's other keys must stay reachable.
[core]
        sshCommand = ssh -i ~/.ssh/id_ed25519_hube_ai.pub -o IdentitiesOnly=yes
