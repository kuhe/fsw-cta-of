const fs = require('fs')
const path = require('path')

async function* walk(dir) {
    for await (const d of await fs.promises.opendir(dir)) {
        const entry = path.join(dir, d.name);
        if (d.isDirectory()) yield* walk(entry);
        else if (d.isFile()) yield entry;
    }
}

// Then, use it with a simple async for loop
async function main() {
    for await (const p of walk(path.join(__dirname, 'resource'))) {
        const contents = fs.readFileSync(p, 'utf-8')
        let buffer = contents;

        const reloadRegex = /"reload time" seconds\(([.\d]+)\)/g
        const reload = buffer.match(reloadRegex);
        if (reload) {
            for (const instance of Array.from(reload)) {
                const seconds = Number(instance.match(/\(([.\d]+)\)/)[1]) | 0;
                let newTiming = Math.min(25, (Math.abs(20 - seconds) / 2 + seconds))
                buffer = buffer.replace(instance, `"reload time" seconds(${newTiming})`)
            }
        }

        fs.writeFileSync(p, buffer, 'utf-8')
    }
}

main().catch(console.error)