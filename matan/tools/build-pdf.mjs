// Сборка PDF из перепечатанного Markdown + LaTeX.
// Зависимости: npm install marked katex marked-katex-extension playwright-core
// Запуск: node build-pdf.mjs <вход.md> <выход.pdf>
import fs from 'fs';
import path from 'path';
import { marked } from 'marked';
import markedKatex from 'marked-katex-extension';
import { chromium } from 'playwright-core';

const [,, src, out] = process.argv;
marked.use({ breaks: true });
marked.use(markedKatex({ throwOnError: false, strict: false, nonStandard: true }));
const md = fs.readFileSync(src, 'utf8');
const body = marked.parse(md);
const css = path.resolve('node_modules/katex/dist/katex.min.css');
const html = `<!doctype html><html lang="ru"><head><meta charset="utf-8">
<link rel="stylesheet" href="file://${css}">
<style>
  @page { size: A4; margin: 18mm 18mm 20mm 18mm; }
  body { font-family: "DejaVu Serif", "Liberation Serif", serif; font-size: 11pt; line-height: 1.45; color: #111; }
  h1 { font-size: 15pt; text-align: center; margin: 1.2em 0 .6em; }
  h2 { font-size: 13pt; text-align: center; margin: 1.2em 0 .5em; }
  h3 { font-size: 11pt; letter-spacing: .05em; margin: 1em 0 .4em; font-family: "DejaVu Sans", sans-serif; }
  p { margin: .35em 0; text-align: justify; hyphens: auto; }
  blockquote { margin: .5em 0 1em; padding: .4em .8em; border-left: 3px solid #999; color: #444; font-size: 9.5pt; }
  .katex-display { margin: .5em 0; }
  code { font-size: 9pt; }
</style></head><body>${body}</body></html>`;
const htmlPath = path.resolve('out.html');
fs.writeFileSync(htmlPath, html);
const browser = await chromium.launch({ executablePath: '/opt/pw-browsers/chromium-1194/chrome-linux/chrome' });
const page = await browser.newPage();
await page.goto('file://' + htmlPath, { waitUntil: 'networkidle' });
const errs = await page.$$eval('.katex-error', els => els.map(e => e.textContent));
console.log('katex errors:', errs.length, errs.slice(0, 10));
const raw = await page.$$eval('p, li', els => els.map(e => e.innerText).filter(t => /\$/.test(t)));
console.log('leftover $:', raw.length, raw.slice(0, 5));
await page.pdf({ path: out, format: 'A4', printBackground: true,
  displayHeaderFooter: true, headerTemplate: '<span></span>',
  footerTemplate: '<div style="font-size:8pt;width:100%;text-align:center;color:#666"><span class="pageNumber"></span></div>',
  margin: { top: '18mm', bottom: '20mm', left: '18mm', right: '18mm' } });
await browser.close();
