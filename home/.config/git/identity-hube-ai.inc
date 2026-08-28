# Identity for repositories owned by the hube-ai GitHub account.
#
# Selected by ~/.gitconfig's includeIf on the remote URL, so a clone is
# attributed correctly the moment it exists and no per-clone setup can be
# forgotten.
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
# account. Pinning is needed only here: against any other remote a wrong key is
# rejected and ssh falls through to the right one, so a global pin would force
# one key at non-GitHub hosts without adding protection.
[core]
        sshCommand = ssh -i ~/.ssh/id_ed25519_hube_ai.pub -o IdentitiesOnly=yes
